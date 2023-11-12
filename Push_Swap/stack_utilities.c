/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:31:43 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/11 14:40:55 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rank_nodes(t_node **stack_a)
{
	unsigned int	index;
	t_node			*current;
	t_node			*aux;

	current = *stack_a;
	index = 0;
	while (current)
	{
		aux = *stack_a;
		while (aux)
		{
			if (current->content > aux->content)
				current->index++;
			aux = aux->next;
		}
		current = current->next;
	}
}

int	number_bits(int argc)
{
	unsigned int	number_bits;
	int				number;

	number = argc - 2;
	number_bits = 0;
	while (number > 0)
	{
		number_bits++;
		number = number / 2;
	}
	return (number_bits);
}

void	handle_top_lt_middle(t_node **stack_a, int top, int middle, int last)
{
	if (top < last && middle > last)
	{
		reverse_rotate_a(stack_a);
		ft_printf("rra\n");
		swap_a(stack_a);
		ft_printf("sa\n");
	}
	else if (top > last && middle > last)
	{
		reverse_rotate_a(stack_a);
		ft_printf("rra\n");
	}
}

void	handle_top_gt_middle(t_node **stack_a, int top, int middle, int last)
{
	if (top < last && middle < last)
	{
		swap_a(stack_a);
		ft_printf("sa\n");
	}
	else if (top > last && middle < last)
	{
		rotate_a(stack_a);
		ft_printf("ra\n");
	}
	else if (top > last && middle > last)
	{
		rotate_a(stack_a);
		ft_printf("ra\n");
		swap_a(stack_a);
		ft_printf("sa\n");
	}
}
