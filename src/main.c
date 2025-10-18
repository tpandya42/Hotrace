/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:41:54 by mmillhof          #+#    #+#             */
/*   Updated: 2025/10/18 16:23:08 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int main(void)
{
	char	*key;
	char	*value;
	int		status;
	
	key = malloc(10000);
	value = malloc(10000);

	status = read_key_value(key, value);
	if (status == 1)
		write(1, "end\n", 4);
	else 
	{
		write(1, key, ft_strlen(key));
		write(1, value, ft_strlen(value));
	}
	free(key);
	free(value);
	return (0);
}
