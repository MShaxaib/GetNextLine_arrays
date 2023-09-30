/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:54:01 by mshazaib          #+#    #+#             */
/*   Updated: 2023/09/14 20:03:13 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd, char *buf, char *str)
{
	int		readlines;
	char	*temp;

	readlines = 1;
	while (readlines != 0)
	{
		readlines = read(fd, buf, BUFFER_SIZE);
		if (readlines == 0)
			break ;
		buf[readlines] = '\0';
		if (!str)
			str = ft_strdup("");
		temp = str;
		str = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (str);
}

char	*extract(char *line)
{
	size_t	count;
	char	*str;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	str = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*str == '\0')
	{
		free(str);
		str = NULL;
	}
	line[count + 1] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*buf;
	char		*line;

	buf = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX || read(fd, buf,
			0) == -1 || fd > 1024)
	{
		if (str[fd])
		{
			free(str[fd]);
			str[fd] = NULL;
		}
		return (0);
	}
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = read_line(fd, buf, str[fd]);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	str[fd] = extract(line);
	return (line);
}
