/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:58:55 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/04 19:38:27 by jaqribei         ###   ########.fr       */
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
		i++;
	}
	check_argument_errors(argc, argv);
}

void	check_argument_errors(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		while (i < argc)
		{
			if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
				exit(ft_printf("Error\nInteger overflow.\n"));
			i++;
		}
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				exit(ft_printf("Error\nDuplicate arguments detected.\n"));
			j++;
		}
		i++;
	}
}


// void	check_integer_overflow(int argc, char *argv[])
// {
// 	int	i;
	
// 	i = 1;
// 	while (i < argc)
// 	{
// 		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
// 			exit(ft_printf("Error\nInteger overflow.\n"));
// 		i++;
// 	}
// }
// 
