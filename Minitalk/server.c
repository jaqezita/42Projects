/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 02:47:19 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/13 15:04:16 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				index;

	(void)context;
	if (signal == SIGUSR1)
		c |= 1;
	index++;
	if (index == 8)
	{
		write(1, &c, 1);
		index = 0;
		c = 0;
	}
	c = c << 1;
	if (signal == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (signal == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	lead;
	sigset_t			set;

	sigemptyset(&set); // initializes the set signal set as empty, meaning no signals are initially included in it.
	sigaddset(&set, SIGUSR1); // adds the signal SIGUSR1 to the set signal set.
	sigaddset(&set, SIGUSR2);
	lead.sa_handler = NULL; // This means that no specific signal handler function is associated with the signals being handled.
	lead.sa_mask = set; // This defines a set of signals that should be blocked while the signal handler is executing.
	lead.sa_flags = SA_SIGINFO; // indicating that the sa_sigaction function, not sa_handler, should be used as the signal handler.
	lead.sa_sigaction = receive_signal; // This is the signal handler function.
	
	
	
	sigaction(SIGUSR1, &lead, NULL); //  The previously defined action struct is used, which specifies the receive_signal function as the handler for these signals.
	sigaction(SIGUSR2, &lead, NULL);
	
	ft_printf("%d\n", getpid());
	while (1)
		pause();
}
