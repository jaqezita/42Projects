/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:34:39 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/07 20:53:24 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node			*stack_a;
	t_node			*stack_b;
	unsigned int	len_a;
	unsigned int	len;
	unsigned int	index;
	int				i;
	int				bits;
	
	stack_a = NULL;
	stack_b = NULL;
	check_errors(argc, argv);
	stack_a = populate_stack(argc, argv);
	print_stack(&stack_a);
	
	index = 0;
	i = 0; 
	max_index(&stack_a);
	len_a = ft_size(stack_a);
	bits = number_bits(argc);
	while (i < bits)
	{
		index = 0;
		while (index < len_a)
		{
			if ((stack_a->index >> i) % 2 == 1)
				rotate_a(&stack_a);
			else
				push_b(&stack_a, &stack_b);
			index++;
		}
		
		index = 0;
		len = ft_size(stack_b);
		while (index < len)
		{
			push_a(&stack_a, &stack_b);
			index++;
		}
		i++;
	}
	write (1, "\n", 1);
	print_stack(&stack_b);
	print_stack(&stack_a);
	write (1, "\n", 1);
	ft_clear(&stack_a, free);
	ft_clear(&stack_b, free);
	return (0);
}
