/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:57:28 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/04 00:52:26 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp_node;

	// pb
	temp_node = stack_b;
	stack_b = stack_b->next;
	temp_node->next = stack_a;
	stack_a = temp_node;
}

void	swap_b(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp_node;

	//sb
	temp_node = stack_b;
	stack_b = stack_b->next;
	temp_node->next = stack_b->next;
	stack_b->next = temp_node;
}

void	rotate_b(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp_node;

	//rb
	temp_node = stack_b;
	stack_b = stack_b->next;
	temp_node->next = NULL;
	ft_lstlast(stack_b)->next = temp_node;
}

void	reverse_rotate_b(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp_node;

	//rrb?
	ft_lstlast(stack_b)->next = temp_node;
	temp_node->next = NULL;
	stack_b = stack_b->next;
	temp_node = stack_b;
}
