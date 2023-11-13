/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:06:16 by ghumm             #+#    #+#             */
/*   Updated: 2023/11/13 15:38:48 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

/*
stati char	line()
{
	
}

static char	*remainder()
{
	
}
*/

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*remainder;
	char		*line;
	ssize_t		read_b;
	char		*newline;

	remainder = NULL;
	if (fd < 0)
		return (NULL);
	if (remainder != NULL && *remainder != '\0')
	{
		line = remainder;
		remainder = NULL;
		return (line);
	}
	read_b = read(fd, buffer, BUFFER_SIZE + 1);
	if (read_b <= 0)
		return (NULL);
	buffer[read_b] = '\0';
	line = buffer;
	newline = ft_strchr(buffer, '\n');
	if (newline != NULL)
	{
		*newline = '\0';
		remainder = newline + 1;
	}
	else
	{
		remainder = buffer + read_b;
	}
	return (line);
}
