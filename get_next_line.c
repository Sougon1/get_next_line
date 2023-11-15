/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:06:16 by ghumm             #+#    #+#             */
/*   Updated: 2023/11/15 12:29:00 by ghumm            ###   ########.fr       */
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

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 8192)
		return (NULL);
	if (remainder != NULL)
	{
		line = remainder;
		remainder = NULL;
		return (line);
	}
	read_b = read(fd, buffer, BUFFER_SIZE);
	if (read_b <= 0)
		return (NULL);
	buffer[read_b] = '\0';
	newline = ft_strchr(buffer, '\n');
	if (newline)
	{
		*newline = '\0';
		line = ft_strdup(buffer);
		if (!line)
			return (NULL);
		if (*(newline + 1) != '\0')
		{
			free(remainder);
			remainder = ft_strdup(newline + 1);
			if (!remainder)
			{
				free(line);
				return (NULL);
			}
		}
	}
	else
	{
		line = ft_strdup(buffer);
		if (!line)
		{
			return (NULL);
		}
	//	free(remainder);
	//	remainder = NULL;
	}
	return (line);
}
