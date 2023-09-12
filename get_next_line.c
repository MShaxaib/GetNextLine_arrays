/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clear <clear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:00:52 by zaibi             #+#    #+#             */
/*   Updated: 2023/09/12 15:16:37 by clear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"

char	*read_line(int fd, char *buf, char *str)
{
	int		readlines;
	char	*temp;

	readlines = 1;
	while (readlines != 0)
	{
		readlines = read(fd, buf, BUFFER_SIZE);
		if (readlines == -1)
		{
			if(str)
			{
			free(str);
			str = NULL;
			}
			return(0);
		}
		else if (readlines == 0)
			break ;
		buf[readlines] = '\0';
		if (!str)
			str = ft_strdup("");
		temp = str;
		str = ft_strjoin(temp, buf);
		if(temp != NULL)
		{
		free(temp);
		temp = NULL;
		}
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
	if (str == NULL)
	{
		free(str);
		str = NULL;
	}
	line[count + 1] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = read_line(fd, buf, str);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	str = extract(line);
	return (line);
}
