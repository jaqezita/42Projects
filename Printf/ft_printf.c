/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:13:08 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/29 19:52:06 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	ft_check_specifier_type(const char *format, va_list args);

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
		}
		if (format[i] == '%')
		{
			// ft_check_specifier_type(format, args);
			if ((format[i + 1] == 'i') || (format[i + 1] == 'd') || (format[i + 1] == 'u'))
			{
				i++;
				ft_number(format, args);
			}
			if (format[i + 1] == 's')
			{
				i++;
				ft_str(format, args);
			}
			if (format[i + 1] == 'c')
			{
				i++;
				ft_chr(format, args);
			}
		}
		i++;
	}
	va_end(args);
	return (0);
}

// void	ft_check_specifier_type(const char *format, va_list args)
// {
// 	int	i;
	
// 	i = 0;
// 	while (format[i] != '\0')
// 	{
// 		if ((format[i + 1] == 'i') || (format[i + 1] == 'd') || (format[i + 1] == 'u'))
// 		{
// 			i++;
// 			ft_number(format, args);
// 		}
// 		if (format[i + 1] == 's')
// 		{
// 			i++;
// 			ft_str(format, args);
// 		}
// 		if (format[i + 1] == 'c')
// 		{
// 			i++;
// 			ft_chr(format, args);
// 		}
// 	}
// }

int	main(void)
{
	// char	*str;
// // 	char	c;
// // 	int		i;

	// str = "bla";
// // 	c = 'x';
// // 	i = 2365478;

	ft_printf("hauhdcuias/  %u/   %d\n%i usahasuh", -1, -1, -1);
	return (0);
}
