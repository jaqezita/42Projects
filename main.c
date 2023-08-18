/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 03:29:20 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/17 23:57:34 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*ft_read(int fd, int size);
void	ft_putstr(char *str);

int main(void)
{
	int		fd;
	int		size;
	char	*buf;
	// char	*aux;
	
	size = 1000;
	fd = open("teste.txt", O_RDONLY);
	// aux = ft_read(fd, size);
	// buf = split_line(aux);
	while (size)
	{
		buf = get_next_line(fd);
		ft_putstr(buf);
		size--;
		if (buf == NULL)
			break;
	}
	close(fd);
	free(buf);
	// free(aux);
	return(0);
}

void	ft_putstr(char *str)
{
		int	 index;

		index = 0;
		while (str[index] != '\0')
		{
				write (1, &str[index], 1);
				index++;
		}
}

