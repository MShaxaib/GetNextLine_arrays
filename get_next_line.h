/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clear <clear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:42:53 by mshazaib          #+#    #+#             */
/*   Updated: 2023/09/12 09:44:31 by clear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

//! Get Next Line functions

char *get_next_line(int fd);
char	*read_line(int fd, char *buf, char *str);
char	*extract(char *line);

//! Get Next Line helper functions

int	ft_strlen(char const *str);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char *ft_substr(const char *s, unsigned int start, size_t len);

#endif