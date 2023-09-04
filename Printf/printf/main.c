/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:29:34 by jaqribei          #+#    #+#             */
/*   Updated: 2023/09/04 18:24:08 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
// #include <string.h>
// #include <limits.h>

int	main(void)
{
	char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
	// char	*str;
	int n;
	// str = "bla";
	n = ft_printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
	printf ("%i\n", n);	
	printf ("\n");
	printf("Retorno: %d\n", printf(" %s %s %s %s %s", " - ", "", "4", "", s2));
	return (0);
}
