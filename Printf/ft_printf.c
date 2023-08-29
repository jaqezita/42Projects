/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:13:08 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/29 00:09:37 by jaqribei         ###   ########.fr       */
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

int	ft_printf(const char *format, ...)
{
	char	c;
	char	*s;
	int		i;
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
			i = va_arg(args, int);
			ft_putnbr_fd(i, 1);
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
	i = 1348435122;
	
	ft_printf("hauhdcuias//%chduilc465778%i", i, c);
	return 0;
}

//       {
//           va_list ap;
//           int d;
    //        char c, *s;

    //        va_start(ap, fmt);
    //        while (*fmt)
    //            switch (*fmt++) {
    //            case 's':              /* string */
    //                s = va_arg(ap, char *);
    //                printf("string %s\n", s);
    //                break;
    //            case 'd':              /* int */
    //                d = va_arg(ap, int);
    //                printf("int %d\n", d);
    //                break;
    //            case 'c':              /* char */
    //                /* need a cast here since va_arg only
    //                   takes fully promoted types */
    //                c = (char) va_arg(ap, int);
    //                printf("char %c\n", c);
    //                break;
    //            }
    //        va_end(ap);
    //    }

