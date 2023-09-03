/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:29:34 by jaqribei          #+#    #+#             */
/*   Updated: 2023/09/02 22:36:21 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
int	ft_printf(const char *format, ...);

int	main(void)
{
	char	*str;

	str = strdup("bla");
	ft_printf("abc/ %u \n %d\n%i abc\n%x\n%X\n%p\n%%\n\n\n", -8, 750, -1, 0xabc123, 68684654, str);
	printf("abc/  %u\n %d\n%i abc\n%x\n%X\n%p\n\n%%", -8, 750, -1, 0xabc123, 68684654, str);
	return (0);
}
