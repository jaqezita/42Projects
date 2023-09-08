/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:13:08 by jaqribei          #+#    #+#             */
/*   Updated: 2023/09/07 20:07:16 by jaqribei         ###   ########.fr       */
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