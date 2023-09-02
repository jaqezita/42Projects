/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:29:34 by jaqribei          #+#    #+#             */
/*   Updated: 2023/09/01 21:13:17 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	char	*str;
// // 	char	c;
// // 	int		i;

	str = "bla";
// // 	c = 'x';
// // 	i = 2365478;

	ft_printf("abc/ %u \n %d\n%i abc\n%x\n%X\n%s\n\n",-8, 750, -1, 0xabc123, 68684654,str);
	printf("abc/  %u\n %d\n%i abc\n%x\n%X\n%s\n\n%p",-8, 750, -1, 0xabc123, 68684654, str, str);
	// ft_printf("%p\n", 10);
	// printf("%p\n", str);
	
	return (0);
}
