/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:41:54 by mmillhof          #+#    #+#             */
/*   Updated: 2025/10/18 17:22:46 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdio.h>

int main(void)
{
	char	*key;
	char	*value;
	int		status;
	
	key = malloc(10000);
	value = malloc(10000);

	while (1)
	{
		status = read_key_value(key, value);
		printf("status: %i\n", status);
		if (status < 0)
			return (0);
		if (status == 0 || key[0] == '\n')
			break ;
	}
	write(1, key, ft_strlen(key));
	write(1, value, ft_strlen(value));
	free(key);
	free(value);
	return (0);
}
