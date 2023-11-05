/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:34:39 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/05 03:27:35 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node			*stack_a;
	t_node			*stack_b;
	unsigned int	len;
	unsigned int	index;
	int				i;
	
	stack_a = NULL;
	stack_b = NULL;
	check_errors(argc, argv);
	stack_a = populate_stack(argc, argv);
	print_stack(&stack_a);
	
	index = 0;
	i = 0; 
	len = ft_size(stack_a);
	// bits = calculate qtd bits of bigest number
	while (i < bits)
	{	
		while (index < len)
		{
			if ((stack_a->index >> i) % 2 == 0)
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
	print_stack(&stack_a);
	write (1, "\n", 1);
	print_stack(&stack_b);
	ft_clear(&stack_a, free);
	ft_clear(&stack_a, free);
	return (0);
}

void	bigger_number(t_node **stack_a)
{
	unsigned int	len;
	unsigned int	index;
	unsigned int	numbers;

	len = ft_size(stack_a);
	while(index < len) 
	{
		while (stack_a->next != NULL)
		{
			
		}
		
	}
}