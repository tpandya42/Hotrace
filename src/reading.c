/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmillhof <mmillhof@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:06:00 by mmillhof          #+#    #+#             */
/*   Updated: 2025/10/18 17:11:45 by mmillhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	read_next_buffer(char *buf, int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	static unsigned int	i;
	static bool	init;
	int			status;

	if (!init)
	{
		stash[0] = '\0';
		i = 0;
		init = true;
	}
	if (!stash[i])
	{
		status = read(fd, stash, BUFFER_SIZE);
		if (status < 0)
			return (-1);
		if (status == 0)
			return (0);
		stash[status + 1] = '\0';
		i = 0;
	}
	*buf = stash[i++];
	return (1);
}

int	read_next_line(char *line)
{
	char 			buf;
	unsigned int	idx;
	int				status;

	idx = 0;
	buf = '\0';
	while (buf != '\n')
	{
		status = read_next_buffer(&buf, 0);
		if (status < 0)
		{
			strerror(errno);
			return (status);
		}
		if (status == 0)
			break ;
		line[idx++] = buf;
	}
	line[idx] = '\0';
	return (idx);
}

int	read_key_value(char *key, char *value)
{
	int		len;

	len = read_next_line(key);
	if (len < 0 || key[0] == '\n')
		return (len);
	len = read_next_line(value);
	if (len < 0 || value[0] == '\n')
		return (-1);
	return (0);
}
