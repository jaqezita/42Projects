/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:27:36 by jaqribei          #+#    #+#             */
/*   Updated: 2024/03/23 21:27:31 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_dinner	*get_input(void)
{
	static t_dinner	input;

	return (&input);
}

int	main(int argc, char *argv[])
{
	t_dinner	*dinner;
	
	if (check_validate_args(argc, argv))
		return 1;
	else
	{
		dinner = init_philo(argc, argv);
		populate_philo();
		// printf("number of philo :%d\n", get_input()->number_of_philos);
		// printf("time of death :%d\n", get_input()->time_to_die);
		// printf("time to eat :%d\n", get_input()->time_to_eat);
		// printf("time to sleep :%d\n", get_input()->time_to_sleep);
		// printf("time to meal :%d\n\n", get_input()->number_of_meals);
		// int	index = 1;
		// while(index <= get_input()->number_of_philos)
		// {
		// 	philo = &get_input()->philos[index];
		// 	printf("philo id :%i\n", philo->id);
		// 	printf("last_meal :%i\n", philo->last_meal);
		// 	index++;
		// }
	}
	return (0);
}