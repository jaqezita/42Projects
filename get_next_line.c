/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 02:29:21 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/16 06:08:46 by jaqribei         ###   ########.fr       */
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
	while (ft_strchr(buf, '\n') == 0)
	{
		read(fd, buf, size);
		if (aux != 0)
			temp = aux;
		aux = ft_strjoin(aux, buf);
	}
	free(buf);
	free (temp);
	return (aux);
}