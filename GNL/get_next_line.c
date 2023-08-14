/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 02:29:21 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/14 04:21:59 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h>

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buf;
	long		index;

	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	if (fd == -1)
		return (NULL);
	if (!line)
	{	
		index = 0;
		while (ft_strchr(buf, '\n') == 0)
		{
			read(fd, buf, BUFFER_SIZE);
		}
		while (buf[index] != '\0')
		{
			if (buf[index] == '\n')
			{	
				line = ft_substr(buf, index + 1, ft_strlen(&buf[index + 1]));
				buf[index] = '\0';
				ft_putstr_fd(buf, 1);
				write(1, "\n", 1);
				break;
			}
			index++;
		}
	}
	else
	{
		buf = ft_strdup(line);
		index = 0;
		while (buf[index] != '\n')
		{
			index++;
		}
		line = ft_substr(buf, index + 1, ft_strlen(&buf[index + 1]));
		buf[index] = '\0';
		ft_putstr_fd(buf, 1);
		write(1, "\n", 1);
	}
	return(NULL);
}

int	main(int argc, char *argv[])
{
	int			fd;
	const char*	Path;

	fd = open(Path, O_RDONLY);
	if (argc > 1)
	{
		fd = open (argv[1], O_RDONLY);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);

		close (fd);
		return (0);
	}
}


