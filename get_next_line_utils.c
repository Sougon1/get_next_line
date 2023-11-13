/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:34:30 by ghumm             #+#    #+#             */
/*   Updated: 2023/11/13 15:27:20 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char    *ft_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }   
    if (*s == (char)c)
        return ((char *)s);
    return (NULL);
}
