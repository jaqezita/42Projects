/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 02:47:19 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/20 07:35:35 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <signal.h>

void	receive_signal(int signal)
{
	static unsigned char	c;
	static int				index;

	if (signal == SIGUSR1)
		c |= 1;
	index++;
	if (index == 8)
	{
		write(1, &c, 1);
		index = 0;
		c = 0;
	}
	else
		c = c << 1;
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, receive_signal);
	signal(SIGUSR2, receive_signal);
	while (1)
		;
	return (0);
}
