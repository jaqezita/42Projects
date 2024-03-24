/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:41:22 by jaqribei          #+#    #+#             */
/*   Updated: 2024/03/23 21:05:21 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	index;
	int	sign;

	sign = 1;
	index = 0;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
			sign = sign * -1;
		index++;
	}
	result = 0;
	while (nptr[index] != '\0' && (nptr[index] >= 48 && nptr[index] <= 57))
	{
		result = result * 10 + nptr[index] - '0';
		index++;
	}
	return (result * sign);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	return (*str == '\0');
}

void	ft_bzero(void *s, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		((unsigned char *)s)[index] = 0;
		index++;
	}
}
