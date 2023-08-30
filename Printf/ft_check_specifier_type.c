/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_specifier_type.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:13:42 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/29 23:20:49 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	ft_check_specifier_type(const char *format, va_list args)
{
	int	index;

	index = 0;
	while (format[index] != '\0')
	{
		if ((format[index + 1] == 'i') || (format[index + 1] == 'd'))
		{
			index++;
			ft_number(format, args);
		}
		if (format[index + 1] == 'u')
		{
			index++;
			ft_number_positive(format, args);
		}
		if (format[index + 1] == 's')
		{
			index++;
			ft_str(format, args);
		}
		if (format[index + 1] == 'c')
		{
			index++;
			ft_chr(format, args);
		}
		index++;
	}
}
