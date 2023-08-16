/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 02:29:21 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/16 03:44:47 by jaqribei         ###   ########.fr       */
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
		while (ft_strchr(buf, '\n') == 0 && fd != -1)
			read(fd, buf, BUFFER_SIZE);
		index = 0;
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
	return (ft_strjoin(buf, line));
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index_suf;
	int		index;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	index_suf = 0;
	index = 0;
	while (s1[index] != '\0')
	{
			result[index] = s1[index];
			index++;
	}
	while (s2[index_suf] != '\0')
	{
			result[index] = s2[index_suf];
			index++;
			index_suf++;
	}
	result[index] = '\0';
	return (result);
}


int	main(int argc, char *argv[])
{
	int			fd;
	int			i;

	if (argc < 1)
		return (1);
	fd = open (argv[1], O_RDONLY);
	i = 0;
	while (i < 30)
	{
		get_next_line(fd);
		i++;
	}
	close (fd);
	return (0);
}
