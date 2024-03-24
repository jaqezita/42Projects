/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:25:18 by jaqribei          #+#    #+#             */
/*   Updated: 2024/03/23 21:06:30 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(int argc, char *argv[])
{
	ft_bzero(get_input(), sizeof(t_dinner));
	get_input()->number_of_philos = ft_atoi(argv[1]);
	get_input()->time_to_die = ft_atoi(argv[2]);
	get_input()->time_to_eat = ft_atoi(argv[3]);
	get_input()->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		get_input()->number_of_meals = ft_atoi(argv[5]);
	get_input()->philos = malloc(get_input()->number_of_philos
		* sizeof(t_philo));
	get_input()->fork = malloc(get_input()->number_of_philos
		* sizeof(pthread_mutex_t));
}

void	populate_philo(void)
{
	int		index;
	t_philo	*philo;

	index = 1;
	while (index <= get_input()->number_of_philos)
	{
		philo = &get_input()->philos[index];
		philo->id = index;
		philo->last_meal = get_time();
		index++;
	}
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
