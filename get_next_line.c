/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 02:29:21 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/16 23:38:15 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, int size)
{
	char	*buf;
	char	*aux;
	char	*temp;

	buf = ft_calloc(size, (sizeof(char *)));
	aux = "\0";
	temp = NULL;
	while (ft_strchr(buf, '\n') == 0)
	{
		read(fd, buf, size);
		aux = ft_strjoin(aux, buf);
		free(temp);
		temp = aux;
	}
	free(buf);
	return (aux);
}
