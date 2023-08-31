/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 00:16:19 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/30 22:32:14 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_recursive_low(size_t n)
{
	char	charnumber;

	if (n / 16 == 0)
	{
		charnumber = (n % 10) + '0';
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

size_t	ft_unsigned_hexa_low(const char *format, va_list args)
{
	while (*format)
	{
		format++;
	}
	return (ft_putnbr_hexa_low((va_arg(args, size_t))));
}

static void	ft_recursive_upper(size_t n)
{
	char	charnumber;

	if (n / 16 == 0)
	{
		charnumber = (n % 10) + '0';
		write (1, &charnumber, 1);
		return ;
	}
	ft_recursive_upper(n / 16);
	charnumber = (n % 16) + '0';
	if (charnumber >= 58 && charnumber <= 63)
		charnumber = charnumber + 7;
	write (1, &charnumber, 1);
}

size_t	ft_putnbr_hexa_upper(size_t n)
{
	ft_recursive_upper(n);
	return (n);
}

size_t	ft_unsigned_hexa_upper(const char *format, va_list args)
{
	while (*format)
	{
		format++;
	}
	return (ft_putnbr_hexa_upper((va_arg(args, size_t))));
}
