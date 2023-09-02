/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 00:47:24 by jaqribei          #+#    #+#             */
/*   Updated: 2023/09/01 20:24:18 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_recursive(size_t n)
{
	char	char_number;

	if (n / 10 == 0)
	{
		char_number = (n % 10) + '0';
		write (1, &char_number, 1);
		return ;
	}
	ft_recursive(n / 10);
	char_number = (n % 10) + '0';
	write (1, &char_number, 1);
}

size_t	ft_putnbr_unsigned(size_t n)
{
	if (n < 0)
	{
		n = n + (4294967295 + 1);
		ft_recursive(n);
	}
	else
		ft_recursive(n);
	return (n);
}

size_t	ft_unsigned_number(va_list args)
{
	unsigned int	n;
	int				count_nbr;

	n = va_arg(args, unsigned int);
	count_nbr = ft_count_numbers(n);
	ft_putnbr_unsigned(n);
	return (count_nbr);
}
