/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 03:29:20 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/22 20:15:47 by jaqribei         ###   ########.fr       */
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
	int		**fd;
	int		size;
	char	*buf;
	char	*path;

	size = 0;
	path = "teste.txt";
	buf = NULL;
	fd = open(path, O_RDONLY);
	while (size < 30)
	{
		buf = get_next_line(*fd[path]);
		if (buf == NULL)
			return (0);
		printf ("%s", buf);
		free (buf);
		size++;
	}
	close (fd);
	return (0);
}
