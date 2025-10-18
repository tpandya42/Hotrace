/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:12:05 by tpandya           #+#    #+#             */
/*   Updated: 2025/10/18 19:37:44 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

/* -> Initializing our hast_table
 * -> Allocating it..
 * -> Also Allocating buckets
 */
t_hashtable	*init_hashes(int size)
{
	t_hashtable	*ht;
	int			i;

	ht = (t_hashtable *)malloc(sizeof(t_hashtable));
	if (!ht)
		return (NULL);
	ht->size = size;
	ht->buckets = (t_nodes **)malloc(ht->size * sizeof(t_nodes *));
	if (!ht->buckets)
		return (free(ht), NULL);
	i = 0;
	while (i < ht->size)
	{
		ht->buckets[i] = NULL;
		i++;
	}
	return (ht);
}

/* DJB2 hashing method....
 * ->Converts Keyword into its hash number
 * ->5381 is magic number.... proven by tests.. Best Efficiency
 * ->We are doing ((hash * 33) + c)
 * ->We do this to scramble bits well so they are nicely distributed
 */
unsigned long long	hashing(char *str)
{
	unsigned long long	hash;
	int					c;

	hash = 5381;
	c = *str;
	while (c)
	{
		hash = ((hash << 5) + hash) + c;
		c = *str++;
	}
	return (hash);
}

/* Getting the correct index...
 * and storing the KEY and VALUES there.....*/
void	insert_into_table(t_hashtable *ht, char *key, char *value)
{
	unsigned long long	hash_value;
	int					index;
	t_nodes				*node;

	hash_value = hashing(key);
	index = hash_value % ht->size;
	node = (t_nodes *)malloc(sizeof(t_nodes));
	node->key = ft_strdup(key);
	node->value = ft_strdup(value);
	node->next = ht->buckets[index];
	ht->buckets[index] = node;
}

/*
 * -> To search for the key in its bucket....
 * -> Getting the bucket via hash value.....
 * -> Returning value of key... in case of existence
 */
char	*search_for_value(t_hashtable *ht, char *key)
{
	unsigned long long	hash_value;
	int					index;
	t_nodes				*current;

	hash_value = hashing(key);
	index = hash_value % ht->size;
	current = ht->buckets[index];
	while (current != NULL)
	{
		if (ft_strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
