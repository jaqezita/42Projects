/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 03:29:20 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/16 06:09:33 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*ft_read(int fd, int size);
void    ft_putstr(char *str);

int main(void)
{
	int	fd;
	int	size = 5;
	char	*buf;

	fd = open("teste.txt", O_RDONLY);
	buf = ft_read(fd, size);
	ft_putstr(buf);
	close(fd);
	free(buf);
	return(0);
}

void    ft_putstr(char *str)
{
        int     index;

        index = 0;
        while (str[index] != '\0')
        {
                write (1, &str[index], 1);
                index++;
        }
}

