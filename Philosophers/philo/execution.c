/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:32:14 by jaqribei          #+#    #+#             */
/*   Updated: 2024/03/23 21:09:07 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_create(void)
{
	int		index;
	t_philo	*philo;

	index = 1;
	while (index <= get_input()->number_of_philos)
	{
		philo = &get_input()->philos[index];
		pthread_create(&philo->philo, NULL, philosopher_routine, (void *)philo);
		index++;
		pthread_join(philo->philo, NULL);
	}
}

int	verify_dinner_state(void)
{
	pthread_mutex_lock(&get_input()->mutex_control_eat);
	pthread_mutex_lock(&get_input()->mutex_dead);
	if (get_input()->is_dead != -1 || get_input()->number_of_meals != 0)
	{
		pthread_mutex_unlock(&get_input()->mutex_control_eat);
		pthread_mutex_unlock(&get_input()->mutex_dead);
		return (1);
	}
	pthread_mutex_unlock(&get_input()->mutex_control_eat);
	pthread_mutex_unlock(&get_input()->mutex_dead);
	return (0);
}
