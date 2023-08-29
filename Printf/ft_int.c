/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 00:47:24 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/29 02:06:54 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "42_libft/libft.h"

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

int	ft_int(const char *format, va_list args)
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
// 	ft_int(args);    // i
// 	ft_string(args); // s
// 	ft_pointer(args);// p
// 	ft_dec(args); //d
// 	ft_unsigned_dec(args); //u
// 	ft_unsigned_hexa_low(args);//x
// 	ft_unsigned_hexa_up(args);//X
// 	ft_char(args);   //c
// }