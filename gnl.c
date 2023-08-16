/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 00:33:30 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/16 04:13:39 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_read(int fd, int size)
{
	char	*buf;
	char	*aux;
	
	buf = ft_calloc((size) * (sizeof(char)));
	aux = malloc((size) * (sizeof(char)));
	while (ft_strchr(buf, '\n') == 0)
	{
		read(fd, buf, size);
		aux = ft_strjoin(aux, buf); 
	}
	return (aux);
}


