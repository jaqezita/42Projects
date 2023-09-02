/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_low.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:27:13 by jaqribei          #+#    #+#             */
/*   Updated: 2023/09/01 21:21:20 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_recursive_low(size_t n)
{
	char	charnumber;

	if (n / 16 == 0)
	{
		charnumber = (n % 16) + '0';
		if (charnumber >= 58 && charnumber <= 63)
			charnumber = charnumber + 39;
		write (1, &charnumber, 1);
		return ;
	}
	ft_recursive_low(n / 16);
	charnumber = (n % 16) + '0';
	if (charnumber >= 58 && charnumber <= 63)
		charnumber = charnumber + 39;
	write (1, &charnumber, 1);
}

size_t	ft_putnbr_hexa_low(size_t n)
{
	ft_recursive_low(n);
	return (n);
}

size_t	ft_numbers_hexa_low(va_list args)
{
	int	n;
	int	count_nbr;

	n = va_arg(args, unsigned int);
	count_nbr = ft_count_numbers(n);
	ft_putnbr_hexa_low(n);
	return (count_nbr);
}
