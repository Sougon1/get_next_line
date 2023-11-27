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
//////////////////////////////////
///////////////////////////////////////

size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	if (c == 0)
	{
		i = ft_strlen((char *)s);
		return (&s[i]);
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
char	*ft_join(char *dest, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
char	*ft_strjoin(char *start, char *buff)
{
	char	*ptr;

	if (!start)
	{
		start = (char *)malloc(1 * sizeof(char));
		start[0] = '\0';
	}
	if (!start || !buff)
		return (NULL);
	ptr = (char *)malloc(1 + ft_strlen(start) + ft_strlen(buff) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr = ft_join(ptr, start, buff);
	free(start);
	return (ptr);
}




char	*ft_readed_line(char *start)
{
	int		i;
	char	*line;

	if (!start || !start[0])
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\n')
		i++;
	line = (char *)malloc(1 + i * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
	{
		line[i] = start[i];
		i++;
	}
	if (start[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_move_start(char	*start)
{
	char	*new_buff;
	int		i;
	int		j;

	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\0')
	{
		free(start);
		return (NULL);
	}
	i += (start[i] == '\n');
	new_buff = (char *)malloc(1 + ft_strlen(start) - i);
	if (!new_buff)
		return (NULL);
	j = 0;
	while (start[i + j])
	{
		new_buff[j] = start[i + j];
		j++;
	}
	new_buff[j] = '\0';
	free(start);
	return (new_buff);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	int			fd_read;
	static char	*start_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd_read = 1;
	tmp = (char *)malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!tmp)
		return (NULL);
	while (!(ft_strchr(start_str, '\n')) && fd_read != 0)
	{
		fd_read = read(fd, tmp, BUFFER_SIZE);
		if (fd_read == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[fd_read] = '\0';
		start_str = ft_strjoin(start_str, tmp);
	}
	free(tmp);
	tmp = ft_readed_line(start_str);
	start_str = ft_move_start(start_str);
	return (tmp);
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
