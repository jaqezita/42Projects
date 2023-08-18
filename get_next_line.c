/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 02:29:21 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/18 00:02:27 by jaqribei         ###   ########.fr       */
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
		if (aux == NULL || bytes_readed == -1)
		{
			free(temp);
			free(buf);
			free (aux);
			return (NULL);
		}
		free(temp);
		temp = aux;
		if (bytes_readed == 0)
			return (NULL);
	}
	if (next != NULL)
		aux = ft_strjoin(next, aux);
	free(buf);
	return (aux);
}

char	*split_line(char *str)
{
	char		*aux;
	int			index;

	index = 0;
	aux = ft_calloc(ft_strlen(str), sizeof(char));
	if (!aux)
		return (NULL);
	while (str[index] != '\n')
	{	
		aux[index] = str[index];
		index++;
	}
	aux[index] = '\n';
	return (aux);
}

// // ft_check_errors
char	*ft_get_rest(char *str)
{
	char	*aux;
	int		i;
	int		index;

	i = 0;
	index = 0;
	aux = ft_calloc(ft_strlen(str), sizeof(char));
	if (!aux)
		return (NULL);
	while (str[index] != '\n')
		index++;
	index++;
	while (str[index] != '\0')
	{
		aux[i] = str[index];
		i++;
		index++;
	}
	// free(aux);
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
	line = split_line(next);
	next = ft_get_rest(next);
	return (line);
}
