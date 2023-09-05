/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:13:08 by jaqribei          #+#    #+#             */
/*   Updated: 2023/09/05 17:21:43 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		index;
	va_list	args;
	int		count;

	va_start(args, format);
	index = 0;
	count = 0;
	while (format[index] != '\0')
	{
		if (format[index] != '%')
		{
			write(1, &format[index], 1);
			count++;
		}
		else if (format[index] == '%')
		{
			count += ft_check_specifier_type(format[index + 1], args);
			index++;
		}
		index++;
	}
	va_end(args);
	return (count);
}

int	ft_check_specifier_type(char format, va_list args)
{
	int	count;

	count = 0;
	if ((format == 'i') || (format == 'd'))
		count += ft_numbers(args);
	else if (format == 'u')
		count += ft_unsigned_number(args);
	else if (format == 's')
		count += ft_str(args);
	else if (format == 'c')
		count += ft_chr(args);
	else if (format == 'x')
		count += ft_numbers_hexa_low(args);
	else if (format == 'X')
		count += ft_numbers_hexa_upper(args);
	else if (format == 'p')
		count += ft_pointer(args);
	else if (format == '%')
		count += ft_percent(format);
	return (count);
}
