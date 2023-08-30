/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 00:47:24 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/29 23:11:36 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void	ft_recursive(size_t n)
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

size_t	ft_putnbr_positive(size_t n)
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

int	ft_number(const char *format, va_list args)
{
	int	index;

	index = 0;
	while (format[index] != '\0')
	{
		if (format[index] == 'u' && format[index] < 0)
		{
			return (ft_putnbr(va_arg(args, int)));
		}
		index++;
	}
	return (ft_putnbr(va_arg(args, int)));
}

unsigned int	ft_number_positive(const char *format, va_list args)
{
	while (*format)
	{
			format++;
	}
	return (ft_putnbr_positive(va_arg(args, unsigned int)));
}
