/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:55:27 by jaqribei          #+#    #+#             */
/*   Updated: 2023/09/01 18:13:56 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_str(va_list args)
{
	char	*str;
	int		count_chr;

	str = va_arg(args, char *);
	count_chr = 0;
	while (str[count_chr] != '\0')
	{
		write (1, &str[count_chr], 1);
		count_chr++;
	}
	return (count_chr);
}

char	ft_chr(va_list args)
{
	int		count_chr;
	char	c;

	c = va_arg(args, int);
	count_chr = write (1, &c, 1);
	return (count_chr);
}
