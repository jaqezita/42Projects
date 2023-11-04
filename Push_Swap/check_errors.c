/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:58:55 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/04 04:47:13 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_errors(int argc, char *argv[])
{
	int	i;
	int	j;
	int	k;

	if (argc < 2 || argv == NULL)
		exit(0);
	i = 1;
	while (i < argc)
	{
		j = i + 1;
		k = 0;
		while (argv[i][k] != '\0')
		{
			if (!ft_isdigit(argv[i][k]) && !(k == 0 && argv[i][k] == '-'))
				exit(ft_printf("Error\nInvalid argument.\n"));
			k++;
		}
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				exit(ft_printf("Error\nDuplicate arguments detected.\n"));
			if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
				exit(ft_printf("Error\nInteger overflow.\n"));
			j++;
		}
		i++;
	}
}
