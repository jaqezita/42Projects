/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 00:16:19 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/30 00:41:28 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	index;
	int	sign;

	sign = 1;
	index = 0;
	while ((nptr[index] >= 9 && nptr[index] <= 13) || nptr[index] == 32)
		index++;
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

static void	ft_recursive(size_t n)
{
	char	charnumber;

	if (n / 16 == 0)
	{
		charnumber = (n % 16 + '0');
		write (1, &charnumber, 1);
		return ;
	}
	ft_recursive(n / 16);
	charnumber = (n % 16) + '0';
	write (1, &charnumber, 1);
}

size_t	ft_putnbr_hexa(size_t n)
{
	// if (n < 0)
	// {
	// 	n = n + (4294967295 + 1);
	// 	ft_recursive(n);
	// }
	// else
		write (1, "0", 1);
		write (1, "x", 1);
		ft_recursive(n);
	return (n);
}

int	ft_unsigned_hexa_low(const char *format, va_list args)
{
	// int	index;

	// index = 0;
	while (*format)
	{
		format++;
	}
	return (ft_putnbr_hexa(va_arg(args, unsigned int)));
}

// char	ft_unsigned_hexa_up(const char *format, va_list args)
// {
// 	int	index;

// 	index = 0;
// 	while (format[index] != '\0')
// 	{
// 		index++;
// 	}
// 	return ();
// }

// char	ft_pointer(const char *format, va_list args)
// {
// 	int	index;

// 	index = 0;
// 	while (format[index] != '\0')
// 	{
// 		index++;
// 	}
// 	return ();
// }