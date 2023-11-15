/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:06:16 by ghumm             #+#    #+#             */
/*   Updated: 2023/11/15 16:17:34 by ghumm            ###   ########.fr       */
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

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 8192)
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
		line = ft_strdup(buffer);
		if (!line)
			return (NULL);
		free(remainder);
		size_t	remlen = ft_strlen(newline +1);
		remainder = (char *)malloc(sizeof(char) * (remlen +1));
		if (!remainder)
		{
			free(line);
			return (NULL);
		}
		ft_strlcpy(remainder, newline +1, remlen +1);
		*newline = '\0';
	}
	else
	{
		line = ft_strdup(buffer);
		if (!line)
			return (NULL);
	}
	return (line);
}
