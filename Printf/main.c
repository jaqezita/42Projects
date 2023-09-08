/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:29:34 by jaqribei          #+#    #+#             */
/*   Updated: 2023/09/07 20:13:42 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdio.h>
// #include <string.h>		}
// #include <limits.h>

// int		ft_printf_bonus(const char *format, ...);

int	main(void)
{
// 	//  char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
// 	//  char	*str;
	int n;
// 	// str = "bla";
	n = ft_printf(" %+d %d", 0, 10);
	printf ("Retorno: %i\n", n);	
	printf ("\n");
	printf("Retorno (verdadeira): %d\n", printf(" %+d %d", 0, 10));
	return (0);
}
