/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:19:43 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/11 22:10:52 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_open_file(const char* Path)
{
	int	fd;
	
	fd = open(Path, O_RDONLY);
	return (fd);
}

char	*get_next_line(int fd)
{
	char			buffer[80];
	char			*copy_buffer;
	unsigned long	index;
	static char		*next;
	unsigned long	size; // sizeof(buf) - index of first '\n'

	// copy_buffer = (char *)ft_calloc(sizeof(buffer) + 1, sizeof(char));
	copy_buffer = buffer;
	size = sizeof(buffer);
	fd = ft_open_file("teste.txt");
	if (fd != -1)
	{
		read (fd, buffer, size);
		index = 0;
		while (index < size)
		{
			if (buffer[index] == '\n')
			{
				next = ft_substr(buffer, index + 1, ft_strlen(&buffer[index + 1]));
				buffer[index] = '\0';
				break;
			}
			index++;
		}
		ft_putstr(buffer);
	}
	return (next);
}
 
int	main(int argc, char *argv[])
{
	int		fd;
	char	buffer[80];

	if (argc == 1)
	{
		ft_putstr("File name missing.\n");
	}
	else if (argc != 2)
	{
		ft_putstr("Too many arguments.\n");
	}
	else
	{
		fd = open (argv[1], O_RDONLY);
		if (fd != -1)
		{
			read (fd, buffer, sizeof(buffer));
			get_next_line(fd);
			close (fd);
		}
		return (0);
	}
}
