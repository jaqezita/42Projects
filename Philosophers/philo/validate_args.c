/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:29:40 by jaqribei          #+#    #+#             */
/*   Updated: 2024/03/23 21:05:52 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	return (*str == '\0');
}

int	check_validate_args(int argc, char *argv[])
{
	if (argc != 6 && argc != 5)
		return (printf("ERROR: Invalid number of arguments"));
	if (!is_number(argv[1]) || !is_number(argv[2]) || !is_number(argv[3])
		|| !is_number(argv[4]) || (argc == 6 && !is_number(argv[5])))
		return (printf("ERROR: Argument is not a number"));
	if (ft_atoi(argv[1]) < 0)
		return (printf("ERROR: At least one philosopher is necessary"));
	if (ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
		return (printf("ERROR: incorrect parameters"));
	return (0);
}
