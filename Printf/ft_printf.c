/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:13:08 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/29 02:11:09 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "42_libft/libft.h"

// void	ft_check_specifier_type(args)
// {
// 	ft_int(args);    // i
// 	ft_string(args); // s
// 	ft_pointer(args);// p
// 	ft_dec(args); //d
// 	ft_unsigned_dec(args); //u
// 	ft_unsigned_hexa_low(args);//x
// 	ft_unsigned_hexa_up(args);//X
// 	ft_char(args);   //c
// }

int	ft_int(const char *format, va_list args);

int	ft_printf(const char *format, ...)
{
	char	c;
	char	*s;
	// int		i;
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
		if (format[index] == '%' && format[index + 1] == 's')    //string
		{
			index++;
			s = va_arg(args, char *);
			write(1, &format[index], 1);
		}
		if (format[index] == '%' && format[index + 1] == 'c') //char
		{
			index++;
			c = (char) va_arg(args, int);
			write(1, &format[index], 1);
		}
		if (format[index] == '%' && format[index + 1] == 'i') //int
		{	
			index++;
			ft_int(format, args);
		}
		index++;
	}
	va_end(args);
	return 0;
}

int	main()
{
	char	*str;
	char	c;
	int		i;

	str = "bla";
	c = 'a';
	i = 2365478;
	
	ft_printf("hauhdcuias//%chduilc465778ygASYGAyg%i", c, i);
	return 0;
}
