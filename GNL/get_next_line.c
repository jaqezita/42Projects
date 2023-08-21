/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 02:29:21 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/21 14:54:59 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, int size, char *next)
{
	char	*buf;
	char	*aux;
	char	*temp;
	long	bytes_readed;

	buf = ft_calloc(size, (sizeof(char *)));
	if (!buf)
		return (NULL);
	aux = NULL;
	temp = NULL;
	while (ft_strchr(aux, '\n') == 0)
	{
		bytes_readed = read(fd, buf, size);
		aux = ft_strjoin(aux, buf);
		if (bytes_readed == 0)
			return (NULL);
		if (ft_check_bytes(bytes_readed, aux, buf, temp) == 0)
			return (NULL);
		free(temp);
		temp = aux;
	}
	if (next != NULL)
		aux = ft_strjoin(next, aux);
	free(buf);
	return (aux);
}

int	ft_check_bytes(long bytes_readed, char *aux, char *buf, char *temp)
{
	if (aux == NULL || bytes_readed == -1)
	{
		free(temp);
		free(buf);
		free (aux);
	}
	return (1);
}

char	*ft_get_line(char *str)
{
	char	*aux;
	int		index;
	int		len;

	len = 0;
	index = 0;
	while (str[len] != '\n')
		len++;
	aux = ft_substr(str, index, len);
	aux[len] = '\n';
	return (aux);
}

char	*ft_get_rest(char *str)
{
	char	*aux;
	int		index;
	int		len;

	len = 0;
	index = ft_strlen (str);
	while (str[len] != '\n')
		len++;
	aux = ft_substr(str, len + 1, index - len);
	return (aux);
}

char	*get_next_line(int fd)
{
	size_t		size;
	static char	*next;
	char		*line;

	if (!fd)
		return (NULL);
	size = BUFFER_SIZE;
	next = ft_read(fd, size, next);
	line = ft_get_line(next);
	next = ft_get_rest(next);
	return (line);
}
