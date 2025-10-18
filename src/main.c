/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:41:54 by mmillhof          #+#    #+#             */
/*   Updated: 2025/10/18 20:23:20 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static int	read_pairs(t_hashtable *ht, char *key, char *value);
static void	search_keys(t_hashtable *ht, char *key);

int	main(void)
{
	char		*key;
	char		*value;
	t_hashtable	*ht;

	ht = init_hashes(100003);
	if (!ht)
		return (1);
	key = malloc(100003);
	value = malloc(100003);
	if (!key || !value)
	{
		clean_table(ht);
		return (1);
	}
	if (read_pairs(ht, key, value) >= 0)
		search_keys(ht, key);
	free (key);
	free (value);
	clean_table(ht);
	return (0);
}

static int	read_pairs(t_hashtable *ht, char *key, char *value)
{
	int		status;

	while (1)
	{
		status = read_key_value(key, value);
		if (status < 0)
		{
			clean_table(ht);
			break ;
		}
		if (key[0] == '\n')
			break ;
		insert_into_table(ht, key, value);
	}
	if (status < 0)
		return (1);
	return (0);
}

static void	search_keys(t_hashtable *ht, char *key)
{
	int			status;
	char		*result;

	while (1)
	{
		status = read_next_line(key);
		if (status < 0 || !ft_strcmp(key, "..."))
			break ;
		if (key[0] == '\n') 
			continue ;
		result = search_for_value(ht, key);
		if (result)
		{
			write(1, result, ft_strlen(result));
			write(1, "\n", 1);
		}
		else
		{
			write(1, key, ft_strlen(key));
			write(1, ": Not found.\n", 13);
		}
	}
}
