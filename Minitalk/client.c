/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 02:47:12 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/20 07:35:48 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <signal.h>

void	send_signal(int pid, unsigned char c)
{
	unsigned char	bit;
	int				index;

	index = 8;
	while (index > 0)
	{
		index--;
		bit = c >> index;
		if (bit % 2 == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(600);
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	index;

	if (argc != 3)
		return (0); // message error
	pid = atoi(argv[1]);
	index = 0;
	while (argv[2][index] != '\0')
	{
		send_signal(pid, argv[2][index]);
		index++;
	}
	return (0);
}
