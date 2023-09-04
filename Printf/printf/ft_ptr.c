/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:32:10 by jaqribei          #+#    #+#             */
/*   Updated: 2023/09/04 17:52:09 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_numbers(int number)
{
	int	count;

	count = 0;
	if (number <= 0)
	{
		count = count + 1;
	}
	while (number != 0)
	{
		count++;
		number = number / 10;
	}
	return (count);
}

int	ft_pointer(va_list args)
{
	size_t	ptr;
	int		count_nbr;


	count_nbr = 0;
	ptr = (size_t)(va_arg(args, void *));
	count_nbr = ft_count_numbers(ptr);
	write(1, "0x", 2);
	ft_putnbr_hexa_low(ptr);
	return (count_nbr);
}

char	ft_percent(char c)
{
	int		count_chr;

	c = '%';
	count_chr = write (1, &c, 1);
	return (count_chr);
}
