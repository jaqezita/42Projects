/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:55:27 by jaqribei          #+#    #+#             */
/*   Updated: 2023/09/04 18:59:07 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str(va_list args)
{
	char	*str;
	int		count_chr;

	str = va_arg(args, char *);
	if (str == NULL)
		return (0);
	count_chr = 0;
	while (str[count_chr] != '\0')
	{
		write (1, &str[count_chr], 1);
		count_chr++;
	}
	return (count_chr);
}

int	ft_chr(va_list args)
{
	int		count_chr;
	char	c;

	c = va_arg(args, int);
	count_chr = write (1, &c, 1);
	return (count_chr);
}
