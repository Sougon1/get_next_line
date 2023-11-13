/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghumm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:32:27 by ghumm             #+#    #+#             */
/*   Updated: 2023/11/13 11:30:59 by ghumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
#endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <sys/types.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);



#endif
