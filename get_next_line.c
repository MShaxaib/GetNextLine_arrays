/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaibi <zaibi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:00:52 by zaibi             #+#    #+#             */
/*   Updated: 2023/09/12 00:00:53 by zaibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"

char	*read_line(int fd, char *buf, char *string)
{
	int		readlines;
	char	*temp;

	readlines = 1;
	while (readlines != '\0')
	{
		readlines = read(fd, buf, BUFFER_SIZE);
		if (readlines == -1)
			return (0);
		else if (readlines == 0)
			break ;
		buf[readlines] = '\0';
		if (!string)
			string = ft_strdup("");
		temp = string;
		string = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (string);
}

char	*extract(char *line)
{
	size_t	count;
	char	*string;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	string = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*string == '\0')
	{
		free(string);
		string = NULL;
	}
	line[count + 1] = '\0';
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = read_line(fd, buf, string);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	string = extract(line);
	return (line);
}
