/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:32:10 by jaqribei          #+#    #+#             */
/*   Updated: 2023/09/01 20:50:50 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(va_list args)
{
	int	*ptr;
	int	count_nbr;

	count_nbr = 0;
	ptr = va_arg(args, void *);
	// count_nbr = ft_count_numbers(ptr);
	// ft_putnbr(ptr);
	return (count_nbr);
}
