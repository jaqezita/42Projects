/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:57:55 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/04 00:53:29 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ss(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp_node;

	// swap a - sa
	temp_node = stack_a;
	stack_a = stack_a->next;
	temp_node->next = stack_a->next;
	stack_a->next = temp_node;
	// swap b - sb
	temp_node = stack_b;
	stack_b = stack_b->next;
	temp_node->next = stack_b->next;
	stack_b->next = temp_node;
}

void	rotate_rr(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp_node;

	// rotate a - ra
	temp_node = stack_a;
	stack_a = stack_a->next;
	temp_node->next = NULL;
	ft_lstlast(stack_a)->next = temp_node;
	// rotate b - rb
	temp_node = stack_b;
	stack_b = stack_b->next;
	temp_node->next = NULL;
	ft_lstlast(stack_b)->next = temp_node;
}

void	reverse_rotate_rrr(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp_node;
}
