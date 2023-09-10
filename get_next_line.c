/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:42:20 by mshazaib          #+#    #+#             */
/*   Updated: 2023/09/10 20:43:18 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// --- reads and puts it in a temp until it founds a new line, 
char 	read_line(int fd, char *buf, char *string)
{
	int readlines;
	char  *temp;

	readlines = 1;
	
	while(readlines != '\0')
	{
		//read the fd
		readlines = read(fd, buf, BUFFER_SIZE);
		//checks
		if(readlines < 0)
			return ;
		//null terminate
		buf[readlines] = '\0';
		//checks
		if(!string)
			string = NULL;
		//swap with temp
		temp = string;
		//join the strings by buf
		string = ft_strjoin(temp, buf);
		//free the goblin
		free(temp);
		temp = NULL;
		//if it finds endline break so it can return the string
		if(ft_strchr('\n', buf))
			break ;
	}
	return(string);
	
}
//-- extract a line given by read_line until the first newline, then should return the line
char *get_next_line(int fd)
{
	static char *string;
	char *buf;
	char *line;

	if(fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if(!buf)
		return (NULL);
	// cpy line(fd, line, string)
	line = cpy_line(fd, buf, string);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);

	
}
