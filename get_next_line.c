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
stati char	line()
{
	
}

static char	*remainder()
{
	
}
*/





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


#include <stdlib.h>
#include <unistd.h>

//#define BUFFER_SIZE 42

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
}

///////////////////////////////////////////////////////
/*
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strndup(const char *s1, int j)
{
	char	*pnt;
	int		i;

	pnt = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!pnt)
		return (NULL);
	i = 0;
	while (s1[i] && i < j)
	{
		pnt[i] = s1[i];
		i++;
	}
	pnt[i] = '\0';
	return (pnt);
}
void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (i < (int)n)
	{
		((char *) s)[i] = 0;
		i++;
	}
}
char	*ft_strnjoin(char const *s1, char const *s2, int i)
{
	int		s1_len;
	int		s3_len;
	char	*s3;
	int		k;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s3_len = ft_strlen(s1) + i;
	s3 = malloc((s3_len + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	ft_bzero(s3, s3_len + 1);
	k = 0;
	j = 0;
	while (k < s3_len)
	{
		if (k < s1_len)
			s3[k] = s1[k];
		else
			s3[k] = s2[j++];
		k++;
	}
	return (s3);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dsts)
{
	size_t	i;

	if (!dsts)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < dsts - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}


//////////////////////////////////////////

int	ft_strchr_i(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	if (s[i] == (unsigned char)c)
		return (i);
	return (-1);
}


int	analyse_buffer(char *buffer, char **line)
{
	char	*s1;
	int	i;
	int	j;
	
	i = ft_strchr_i(buffer, '\n');
	if (i != -1)
	{
		j = ft_strchr_i(&buffer[i + 1], '\n');
		free(*line);
		if (j != -1)
		{
			*line = ft_strndup(&buffer[i + 1], j + 1);
			s1 = ft_strndup(&buffer[i + 1], BUFFER_SIZE);
			ft_strlcpy(buffer, s1, BUFFER_SIZE);
			free(s1);
			return (1);
		}
		else
			*line = ft_strndup(&buffer[i + 1], BUFFER_SIZE);
	}
	return (-1);
}


void	analyse_fd(char *buffer, char **line, int  fd)
{
	char	*s1;
	int	read_size;

	read_size = 1;
	while (read_size > 0)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (ft_strchr_i(buffer, '\n') == -1 && read_size != 0)
		{
			s1 = ft_strndup(*line, ft_strlen(*line));
			free(*line);
			*line = ft_strnjoin(s1, buffer, BUFFER_SIZE);
			free(s1);
		}
		else
		{
			s1 = ft_strndup(*line, ft_strlen(*line));
			free(*line);
			*line = ft_strnjoin(s1, buffer, ft_strchr_i(buffer, '\n') + 1);
			free(s1);
			break ;
		}
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (read(fd, buffer, 0) < 0)
		return (NULL);
	line = malloc(1 * sizeof(char));
	if (!line)
		return (NULL);
	ft_bzero(line, 1);
	if (analyse_buffer((char *)&buffer, &line) == -1)
		analyse_fd((char *)&buffer, &line, fd);
	if (line[0] == 0 && ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
*/
/////////////////////////////////////////////////////////////


/*
void print_test_result(int test_number, const char *result, const char *expected)
{
    printf("Test %d: ", test_number);
    
    if (result == NULL || expected == NULL)
    {
        printf("FAILED (Result or Expected is NULL)\n\n");
    }
    else if (strcmp(result, expected) == 0)
    {
        printf("PASSED\n\n");
    }
    else
    {
        printf("FAILED \nResult: \"%s\" \nExpected: \"%s\"\n\n", result, expected);
    }
}

int	main(void)
{
	int		fd;
	char	*line;

	// Test 1: Fichier avec une seule ligne
	fd = open("text1.txt", O_RDONLY);
	line = get_next_line(fd);
	print_test_result(1, line, "");
	free(line);
	close(fd);

	// Test 2: Fichier vide
	fd = open("text2.txt", O_RDONLY);
	line = get_next_line(fd);
	print_test_result(2, line, "b");
	free(line);
	close(fd);

	// Test 3: Fichier sans caractère de nouvelle ligne
	fd = open("text3.txt", O_RDONLY);
	line = get_next_line(fd);
	print_test_result(3, line, "\n");
	free(line);
	close(fd);
	
	// ... Ajoutez d'autres tests ...

	return (0);
}*/

