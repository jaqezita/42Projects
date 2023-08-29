/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 00:47:24 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/29 19:01:39 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void	ft_recursive(int n)
{
	char	charnumber;

	if (n / 10 == 0)
	{
		charnumber = (n % 10) + '0';
		write (1, &charnumber, 1);
		return ;
	}
	ft_recursive(n / 10);
	charnumber = (n % 10) + '0';
	write (1, &charnumber, 1);
}

int	ft_putnbr(int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		if (n == -2147483648)
		{
			write (1, "2", 1);
			n = n + 2000000000;
		}
		n *= -1;
		ft_recursive(n);
	}
	else
		ft_recursive(n);
	return (n);
}

int	ft_number(const char *format, va_list args)
{
	int	index;

	index = 0;
	while (format[index] != '\0')
	{
		index++;
	}
	return (ft_putnbr(va_arg(args, int)));
}

// void	ft_check_specifier_type(args)
// {

// 	ft_pointer(args);// p
// 	ft_unsigned_hexa_low(args);//x
// 	ft_unsigned_hexa_up(args);//X
// }