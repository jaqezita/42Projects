/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_determinate_size_handlers.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:34:01 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/10 20:41:12 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_two_number_stack(t_node **stack_a)
{
	swap_a(stack_a);
}

void	handle_three_number_stack(t_node **stack_a)
{
	t_node	*current;
	int		first;
	int		middle;
	int		last;

	current = *stack_a;
	last = ft_last(current)->index;
	first = current->index;
	middle = current->next->index;

	if (first < middle)
		case_one(stack_a, first, middle, last);
	if (first > middle)
		case_two(stack_a, first, middle, last);
}

void	case_one(t_node **stack_a, int first, int middle, int last)
{
	if (first < last && middle > last)
	{
		reverse_rotate_a(stack_a);
		ft_printf("rra\n");
		swap_a(stack_a);
		ft_printf("sa\n");
	}
	else if (first > last && middle > last)
	{
		reverse_rotate_a(stack_a);
		ft_printf("rra\n");
	}
}

void	case_two(t_node **stack_a, int first, int middle, int last)
{
	if (first < last && middle < last)
	{
		swap_a(stack_a);
		ft_printf("sa\n");
	}
	else if (first > last && middle < last)
	{
		rotate_a(stack_a);
		ft_printf("ra\n");
	}
	else if (first > last && middle > last)
	{
		rotate_a(stack_a);
		ft_printf("ra\n");
		swap_a(stack_a);
		ft_printf("sa\n");
	}
}