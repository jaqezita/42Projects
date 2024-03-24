/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:32:40 by jaqribei          #+#    #+#             */
/*   Updated: 2024/03/23 21:27:03 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (!verify_dinner_state())
	{
		if (!verify_dinner_state())
			set_philosopher_state(philo, THINKING);
		usleep(10);
		if (!verify_dinner_state())
			philo_eat_routine(philo, EATING);
		if (!verify_dinner_state())
			philo_eat_routine(philo, SLEEPING);
	}
	return (0);
}
	
// 	printf("philo id :%i\n", philo->id);
// 	printf("last_meal :%i\n", philo->last_meal);
		
// 	return (NULL);
// }

void	philo_eat_routine(t_philo *philo, enum e_philo_state mode)
{
	int	first_fork;
	int second_fork;
	
	if (philo->id % 2 == 0)
	{
		first_fork = philo->id;
		second_fork = philo->id - 1;
		if (philo->id == 0)
			second_fork = get_input()->number_of_philos -1;
	}
	else
	{
		first_fork = philo->id;
		second_fork = philo->id;
		usleep(1000);
	}
	if (philo_take_forks(philo, first_fork, second_fork, mode))
		return ;
	pthread_mutex_lock(&get_input()->mutex_state);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&get_input()->mutex_state);
	usleep(get_input()->time_to_eat * 1000);
	pthread_mutex_unlock(&get_input()->fork[first_fork]);
	pthread_mutex_unlock(&get_input()->fork[second_fork]);
}

void	philo_sleep_routine(t_philo *philo, enum e_philo_state mode)
{
	if (!verify_dinner_state)
	{
		set_philosopher_state(philo, mode);
		pthread_mutex_lock(&get_input()->mutex_state);
		philo->number_of_meals++;
		pthread_mutex_unlock(&get_input()->mutex_state);
		if (&get_input()->time_to_sleep)
			usleep(get_input()->time_to_sleep * 1000);
	}
	return ;
}

void	set_philosopher_state(t_philo *philo, enum e_philo_state mode)
{
	long	time;
	long	current_time;

	current_time = get_time();
	time = current_time - get_input()->program_start;
	pthread_mutex_lock(&get_input()->mutex_state);   // Update the philosopher's state with the new mode and the time
	philo->state = (t_philo_state){mode, time};
	pthread_mutex_lock(&get_input()->mutex_state);
	print_state (philo, mode);
}

int	philo_take_forks(t_philo *philo, int first, int second, enum e_philo_state mode)
{
	if(verify_dinner_state())
		return (1);
	pthread_mutex_lock(&get_input()->fork[first]);
	set_philosopher_state(philo, HAS_FORK);
	if (verify_forks(first, 0))
		return (1);
	pthread_mutex_lock(&get_input()->fork[second]);
	set_philosopher_state(philo, HAS_FORK);
	if (verify_forks(first, second))
		return (1);
	set_philosopher_state(philo, mode);
	return (0);
}

int	verify_forks(int first, int second)
{
	if(verify_dinner_state())
	{
		pthread_mutex_unlock(&get_input()->fork[first]);
		if (second)
			pthread_mutex_unlock(&get_input()->fork[second]);
		return (1);
	}
	return (0);
}

void	print_state(t_philo *philo, enum e_philo_state mode)
{
	long	time;
	char	*status[5];
	
	status = {"has taken a fork", "is eating", "is sleeping", "is thinking", "died"}[mode];
	
	time = get_time() - get_input()->program_start;
	if (!ig_the_check())
	{
		pthread_mutex_lock(&get_input()->mutex_print);
		printf("%ld %d %s\n", time, philo->id + 1, status);
		pthread_mutex_unlock(&get_input()->mutex_print);
	}
}
