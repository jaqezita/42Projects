/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:13:08 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/30 22:42:01 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		index;
	va_list	args;

	va_start(args, format);
	index = 0;
	while (format[index] != '\0')
	{
		if (format[index] != '%')
		{
			write(1, &format[index], 1);
		}
		if (format[index] == '%')
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
			if (format[index + 1] == 'x')
			{
			 	index++;
			 	ft_unsigned_hexa_low(format, args);
			}
			if (format[index + 1] == 'X')
			{
				index++;
				ft_unsigned_hexa_upper(format, args);
			}
		// // 	if (format[index + 1] == 'p')
		// // 	{
		// // 		index++;
		// // 		ft_pointer(format, args);
		// // 	}
		}
		index++;
	}
	va_end(args);
	return (index);
}

#include <stdio.h>

int	main(void)
{
	char	*str;
// // 	char	c;
// // 	int		i;

	str = "bla";
// // 	c = 'x';
// // 	i = 2365478;

	// ft_printf("abc/  %u/   %d\n%i abc\n%x\n%X\n\n", -89, 750, -1, -68684654, 68684654);
	// printf("abc/  %u/   %d\n%i abc\n%x\n%X\n\n", -89, 750, -1, -68684654, 68684654);
	// ft_printf("%p\n", 10);
	printf("%p\n", str);
	return (0);
}

