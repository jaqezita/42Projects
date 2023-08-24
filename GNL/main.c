/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 03:29:20 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/24 16:11:32 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		size;
	char	*buf;

	size = 0;
	buf = NULL;
	fd = open("teste.txt", O_RDONLY);
	// *fd = open("teste2.txt", O_RDONLY);
	while (size < 20)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			return (0);
		printf ("%s", buf);
		free (buf);
		size++;
	}
	close (fd);
	return (0);
}
