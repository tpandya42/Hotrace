/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:41:54 by mmillhof          #+#    #+#             */
/*   Updated: 2025/10/18 17:13:24 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int main(void)
{
	t_hashtable	*ht;
	char		*key;
	char		*value;
	char		*result;
	int			status;
	
	ht = init_hashes(100003);
	if (!ht)
		return (1);
	
	key = malloc(10000);
	value = malloc(10000);
	if (!key || !value)
	{
		clean_table(ht);
		return (1);
	}

	while (1)
	{
		status = read_key_value(key, value);
		if (status <= 0)
			break ;

		if (key[0] == '\n')
			break ;
		if (key[ft_strlen(key) - 1] == '\n')
			key[ft_strlen(key) - 1] = '\0';
		
		insert_into_table(ht, key, value);
	}

	while (1)
	{
		status = read_next_line(key);
		if (status <= 0)
			break ;

		if (key[0] == '\n') 
			continue;

		if (key[ft_strlen(key) - 1] == '\n')
			key[ft_strlen(key) - 1] = '\0';

		result = search_for_value(ht, key);
		if (result)
		{
			write (1, result, ft_strlen(result));
			write (1, "\n", 1);
		}
		else
		{
			write (1, key, ft_strlen(key));
			write (1, ": Not found.\n", 13);		
		}
	}

	free(key);
	free(value);
	clean_table(ht);
	return (0);
}
