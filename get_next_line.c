/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:06:16 by ghumm             #+#    #+#             */
/*   Updated: 2023/11/17 14:12:56 by ghumm            ###   ########.fr       */
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

/*
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
		line = ft_strdup(remainder);
		free(remainder);
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
		size_t	remlen = ft_strlen(newline + 1);
		remainder = (char *)malloc(sizeof(char) * (remlen + 1));
		if (!remainder)
		{
			free(line);
			return (NULL);
		}
		ft_strlcpy(remainder, newline + 1, remlen + 1);
		*newline = '\0';
	}
	else
	{
		line = ft_strdup(buffer);
		if (!line)
			return (NULL);
	}
	return (line);
}*/


#include <unistd.h>
#include <stdlib.h>

char *ft_strdup(const char *s)
{
    size_t len = 0;
    while (s[len] != '\0')
        len++;

    char *dup = (char *)malloc((len + 1) * sizeof(char));
    if (!dup)
        return (NULL);

    for (size_t i = 0; i <= len; i++)
        dup[i] = s[i];

    return (dup);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    if (!s1 || !s2)
        return (NULL);

    size_t len1 = 0;
    while (s1[len1] != '\0')
        len1++;

    size_t len2 = 0;
    while (s2[len2] != '\0')
        len2++;

    char *result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    if (!result)
        return (NULL);

    for (size_t i = 0; i < len1; i++)
        result[i] = s1[i];

    for (size_t i = 0; i < len2; i++)
        result[len1 + i] = s2[i];

    result[len1 + len2] = '\0';
    return (result);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    if (!s)
        return (NULL);

    size_t s_len = 0;
    while (s[s_len] != '\0')
        s_len++;

    if (start >= s_len)
        return (ft_strdup(""));

    size_t substr_len = (len < s_len - start) ? len : (s_len - start);
    char *substr = (char *)malloc((substr_len + 1) * sizeof(char));
    if (!substr)
        return (NULL);

    for (size_t i = 0; i < substr_len; i++)
        substr[i] = s[start + i];

    substr[substr_len] = '\0';
    return (substr);
}

char *ft_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return ((char *)s);

        s++;
    }

    if (c == '\0')
        return ((char *)s);

    return (NULL);
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static char *remainder = NULL;
    char *line = NULL;
    char *temp = NULL;
    int bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        temp = remainder;
        remainder = temp ? ft_strjoin(temp, buffer) : ft_strdup(buffer);
        free(temp);

        if (ft_strchr(remainder, '\n'))
            break;
    }

    if (bytes_read == -1 || (bytes_read == 0 && (remainder == NULL || remainder[0] == '\0')))
    {
        free(remainder);
        return (NULL);
    }

    int len = 0;
    while (remainder[len] != '\n' && remainder[len] != '\0')
        len++;

    line = ft_substr(remainder, 0, len);
    temp = remainder;
    remainder = (remainder[len] == '\n') ? ft_strdup(temp + len + 1) : NULL;
    free(temp);

    return (line);
}

