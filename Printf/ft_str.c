/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:55:27 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/29 23:11:41 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

char	ft_putstr(char *s)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		write (1, &s[index], 1);
		index++;
	}
	return (*s);
}

char	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

char	ft_str(const char *format, va_list args)
{
	int	index;

	index = 0;
	while (format[index] != '\0')
	{
		index++;
	}
	return (ft_putstr(va_arg(args, char *)));
}

char	ft_chr(const char *format, va_list args)
{
	int	index;

	index = 0;
	while (format[index] != '\0')
	{
		index++;
	}
	return ((char)ft_putchar(va_arg(args, int)));
}

// void	ft_check_specifier_type(args)
// {

// 	ft_pointer(args);// p
// 	ft_unsigned_hexa_low(args);//x
// 	ft_unsigned_hexa_up(args);//X
// }