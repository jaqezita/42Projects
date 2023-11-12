/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:34:39 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/12 16:37:09 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		bits;

	stack_a = NULL;
	stack_b = NULL;
	error_check(argc, argv);
	stack_a = populate_stack(argc, argv);
	if (is_stack_sorted(&stack_a))
	{
		ft_clear(&stack_a, free);
		return (0);
	}
	rank_nodes(&stack_a);
	print_stack(&stack_a);
	write (1, "\n", 1);
	if (ft_size(stack_a) == 3)
		handle_three_number_stack(&stack_a);
	bits = number_bits(argc);
	if (ft_size(stack_a) == 5)
		handle_five_number_stack(&stack_a, &stack_b);
	else
	radix_sort_binary(&stack_a, &stack_b, bits);
	write (1, "\n", 1);
	print_stack(&stack_b);
	write (1, "\n", 1);
	print_stack(&stack_a);
	write (1, "\n", 1);
	ft_clear(&stack_a, free);
	ft_clear(&stack_b, free);
	return (0);
}
