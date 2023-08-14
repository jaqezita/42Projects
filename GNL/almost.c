/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:19:43 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/14 02:15:13 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
	
	//LOCALIZAR \N
	//ARMAZENAR READ ATUAL EM VARIAVEL ESTATICA
	//Verify if it's first time calling the function

char	*ft_first_read(char *buffer, int fd)
{
	int			index;
	static char	*next;
	
	next = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read(fd, buffer, BUFFER_SIZE);
	index = 0;
	while (index < BUFFER_SIZE)
	{
		if (buffer[index] == '\n')
		{
			next = ft_substr(buffer, index + 1, ft_strlen(&buffer[index + 1]));
			buffer[index] = '\0';
			break;
		}
		index++;
	}
	ft_putstr_fd(buffer, 1);
	return (next);
}

char	*ft_next_read(char *next)
{
	int		index;
	char	*buf;

	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	index = 0;
	while (next[index])
	{
		buf[index] = next[index];
		if (next[index] == '\n')
		{
			next = ft_substr(buf, index + 1, ft_strlen(&buf[index + 1]));
			buf[index] = '\0';
			break;
		}
		index++;
	}
	ft_putstr_fd(buf, 1);
	return (next);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*next;

	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char)); 
	next = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (fd != -1)
		ft_first_read(buffer, fd);
	return (next);
}

int	main(int argc, char *argv[])
{
	int			fd;
	const char*	Path;

	fd = open(Path, O_RDONLY);
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
			get_next_line(fd);
			get_next_line(fd);
			get_next_line(fd);
			close (fd);
		}
		return (0);
	}
}
