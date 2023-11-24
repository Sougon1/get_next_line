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


/*

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
*/

#include <stdlib.h>
#include <unistd.h>

//#define BUFFER_SIZE 10
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


//#define BUFFER_SIZE 42
/*
char *get_next_line(int fd)
{
    int     byte;
    char    *str_buffer;
    int     i;

    if (BUFFER_SIZE < 1 || fd < 0)
        return (NULL);
    
    i = 0;
    str_buffer = (char *)malloc(100000000);
    
    if (!str_buffer)
        return (NULL);
    
    byte = read(fd, str_buffer, BUFFER_SIZE);
    
    while (byte > 0)
    {
        i += byte;

        // Recherche du caractère '\n' dans la partie du tampon qui vient d'être lue
        int j = 0;
        while (j < byte)
        {
            if (str_buffer[j] == '\n')
            {
                break;
            }
            j++;
        }

        if (j < byte) // '\n' trouvé
            break;
	j = 0;
        byte = read(fd, str_buffer + i, BUFFER_SIZE);
    }

    // Plus de caractères ou une erreur s'est produite
    if (i == 0 || byte < 0)
    {
        free(str_buffer);
        return (NULL);
    }

    str_buffer[i] = '\0';

    return (str_buffer);
}
*/

size_t	ft_strlen(const char *theString)
{
	int	i;

	i = 0;
	while (theString[i])
		i++;
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	sizetotal = (ft_strlen(s1) + ft_strlen(s2));
	res = malloc(sizeof(char) * (sizetotal + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[sizetotal] = 0;
	return (res);
}

char	*ft_strchr(const char *string, int searchedChar )
{
	char	*str;

	str = (char *)string;
	while (*str != searchedChar && *str != 0)
		str++;
	if (*str == searchedChar)
		return (str);
	else
		return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*res;

	res = malloc(elementSize * elementCount);
	if (!res)
		return (NULL);
	ft_bzero(res, elementSize * elementCount);
	return (res);
}


char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

// delete line find
char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	// find len of first line
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// if eol == \0 return NULL
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	// len of file - len of firstline + 1
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	// line == buffer
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

// take line for return
char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	// if no line return NULL
	if (!buffer[i])
		return (NULL);
	// go to the eol
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// malloc to eol
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	// line = buffer
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	// if eol is \0 or \n, replace eol by \n
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	// malloc if res dont exist
	if (!res)
		res = ft_calloc(1, 1);
	// malloc buffer
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		// while not eof read
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		// 0 to end for leak
		buffer[byte_read] = 0;
		// join and free
		res = ft_free(res, buffer);
		// quit if \n find
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	// error handling
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
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
}*/





/*

int main(void)
{
    int     fd;
    char    *str;
    char    *path;
    int     i;

    path = "text2.txt";
    fd = open(path, O_RDONLY);
    i = 0;
    while(i < 7) // number of loop (test)
    {
        str = get_next_line(fd);
        printf("i%i\n", i);
        printf("fd: %s\n", str);
        i++;
    }
    return (0);
}
*/
