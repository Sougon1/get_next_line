/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:06:16 by ghumm             #+#    #+#             */
/*   Updated: 2023/11/14 14:57:00 by ghumm            ###   ########.fr       */
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (remainder != NULL || *remainder != '\0')
	{
		line = remainder;
		remainder = NULL;
	}
	read_b = read(fd, buffer, BUFFER_SIZE);
	if (read_b <= 0)
	{
		return (NULL);
	}
	buffer[read_b] = '\0';
	newline = ft_strchr(buffer, '\n');
	if (newline != NULL)
	{
		*line = '\0';
		remainder = ft_strdup(newline + 1);
		if (!remainder)
		{
			return (NULL);
		}
	}
	else
	{
		remainder = ft_strdup(buffer + read_b);
		if (!remainder)
		{
			return (NULL);
		}
	}
	if (!line)
		return (NULL);
	
	return (line);
}
