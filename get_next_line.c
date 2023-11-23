/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:06:16 by ghumm             #+#    #+#             */
/*   Updated: 2023/11/20 11:38:50 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include "get_next_line.h"


#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>




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


#include <stdlib.h>
#include <unistd.h>

//#define BUFFER_SIZE 42
/*
char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*remainder = NULL;
	char		*line;
	int			read_b;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	read_b = read(fd, buffer, BUFFER_SIZE);

	while (read_b > 0)
	{
		buffer[read_b] = '\0';
		temp = remainder;
		remainder = (temp) ? ft_strjoin(temp, buffer) : ft_strdup(buffer);
		free(temp);

		if (!remainder)
			return (NULL);

		if (ft_strchr(remainder, '\n'))
			break;
		read_b = read(fd, buffer, BUFFER_SIZE);
	}

	if (read_b <= 0 && (!remainder || remainder[0] == '\0'))
	{
		free(remainder);
		return (NULL);
	}

	int len = 0;
	while (remainder[len] != '\0')
		len++;
	
	
	line = ft_substr(remainder, 0, len);

	if (!line)
	{
		free(remainder);
		return (NULL);
	}
	
	if (remainder[len] == '\n')
	{
		temp = remainder;
		remainder = ft_strdup(temp + len + 1);
		free(temp);
	}
	else
	{
		free(remainder);
		remainder = NULL;
	}


	return (line);
}*/

#define BUFFER_SIZE 42
#define MAX_LINE_SIZE 1024

char *get_next_line(int fd)
{
    int     byte;
    char    *str_buffer;
    int     i;

    if (BUFFER_SIZE < 1 || fd < 0)
        return (NULL);
    i = 0;
    str_buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (!str_buffer)
        return (NULL);
    byte = read(fd, str_buffer + i, BUFFER_SIZE);
    while (byte > 0)
    {
    	i += byte;
        if(str_buffer[i - 1] == '\n')
            break ;
	if (i == MAX_LINE_SIZE)
	{
		free(str_buffer);
		return (NULL);
	}
        byte = read(fd, str_buffer + i, BUFFER_SIZE);
    }
    // no more char OR error happens
    if (i == 0 || byte < 0)
    {
        free(str_buffer);
        return (NULL);
    }
    str_buffer[i] = '\0';
    return (str_buffer);
}



///////////////////////////////////////////////
//////////////FONCTIONEL
/////
/*
char *get_next_line(int fd)
{
    int     byte;
    char    c;
    char    *str_buffer;
    int     i;

    if (BUFFER_SIZE < 1 || fd < 0)
        return (NULL);
    i = 0;
    str_buffer = (char *)malloc(10000000);
    if (!str_buffer)
        return (NULL);
    byte = read(fd, &c, 1); // each every one character from txt file
    while (byte > 0)
    {
        str_buffer[i] = c;
        i++;
        if(c == '\n' || c == EOF)
            break ;
        byte = read(fd, &c, 1); // each every one character from txt file
    }
    // no more char OR error happens
    if (i == 0 || byte < 0)
    {
        free(str_buffer);
        return (NULL);
    }
    str_buffer[i] = '\0';
    return (str_buffer);
}
*/






int main(void)
{
    int     fd;
    char    *str;
    char    *path;
    int     i;

    path = "text2.txt";
    fd = open(path, O_RDONLY);
    i = 0;
    while(i < 10) // number of loop (test)
    {
        str = get_next_line(fd);
        printf("i: %i\n", i);
        printf("fd: %i, %s\n", fd, str);
        i++;
    }
    return (0);
}

