/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 02:29:21 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/14 05:50:22 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buf;
	int			index;

	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (fd == -1)
		return (NULL);
	if (line == NULL)
	{	
		index = 0;
		while (ft_strchr(buf, '\n') == 0)
			read(fd, buf, BUFFER_SIZE);
		while (buf[index] != '\0')
		{
			if (buf[index] == '\n')
			{	
				line = ft_substr(buf, index + 1, ft_strlen(&buf[index + 1]));
				buf[index] = '\0';
				ft_putstr_fd(buf, 1);
				write (1, "\n", 1);
				break ;
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
			if (buf[index] == '\0')
				return (NULL);
			index++;
		}
		line = ft_substr(buf, index + 1, ft_strlen(&buf[index + 1]));
		buf[index] = '\0';
		ft_putstr_fd(buf, 1);
		write (1, "\n", 1);
	}
	return (buf);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb != (nmemb * size) / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, (nmemb * size));
	return (ptr);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		((unsigned char *)s)[index] = c;
		index++;
	}
	return (s);
}

int	main(int argc, char *argv[])
{
	int			fd;
	int			i;

	if (argc < 1)
		return (1);
	fd = open (argv[1], O_RDONLY);
	i = 0;
	while (i < 20)
	{
		get_next_line(fd);
		i++;
	}
	close (fd);
	return (0);
}
