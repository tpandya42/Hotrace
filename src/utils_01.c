/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:12:11 by tpandya           #+#    #+#             */
/*   Updated: 2025/10/18 19:12:12 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	clean_buckets(t_nodes *nodes)
{
	t_nodes	*current;
	t_nodes	*next;

	current = nodes;
	while (current != NULL)
	{
		next = current->next;
		free(current->key);
		free(current->value);
		free(current);
		current = next;
	}
}

void	clean_table(t_hashtable *ht)
{
	int	i;

	if (!ht)
		return ;
	i = 0;
	while (i < ht->size)
	{
		if (ht->buckets[i] != NULL)
			clean_buckets(ht->buckets[i]);
		i++;
	}
	free(ht->buckets);
	free(ht);
}
