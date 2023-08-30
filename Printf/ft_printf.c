/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:13:08 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/29 23:12:17 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

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
		}
		index++;
	}
	va_end(args);
	return (0);
}

// int	main(void)
// {
// 	// char	*str;
// // // 	char	c;
// // // 	int		i;

// 	// str = "bla";
// // // 	c = 'x';
// // // 	i = 2365478;

// 	ft_printf("hauhdcuias/  %u/   %d\n%i usahasuh", -1, -1, -1);
// 	return (0);
// }
