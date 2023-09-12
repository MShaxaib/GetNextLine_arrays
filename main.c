/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:04:21 by mshazaib          #+#    #+#             */
/*   Updated: 2023/09/12 19:05:06 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int fd; // File descriptor
	char *line;

	// Open a file for reading (replace 'your_file.txt' with your file)
	fd = open("testfile.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening the file");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
	}
	return (0);
}