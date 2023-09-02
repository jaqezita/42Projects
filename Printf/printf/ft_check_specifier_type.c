/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_specifier_type.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:13:42 by jaqribei          #+#    #+#             */
/*   Updated: 2023/09/01 20:52:08 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_specifier_type(char format, va_list args)
{
	int	index;

	index = 0;
	if ((format == 'i') || (format == 'd'))
		index += ft_numbers(args);
	if (format == 'u')
		index += ft_unsigned_number(args);
	if (format == 's')
		index += ft_str(args);
	if (format == 'c')
		index += ft_chr(args);
	if (format == 'x')
		index += ft_numbers_hexa_low(args);
	if (format == 'X')
		index += ft_numbers_hexa_upper(args);
	if (format == 'p')
		index += ft_pointer(args);
	return (index);
}
