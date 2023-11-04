/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:57:17 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/04 05:09:04 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp_node;

	//pa
	temp_node = stack_a;
	stack_a = stack_a->next;
	temp_node->next = stack_b;
	stack_b = temp_node;
}

void	swap_a(t_list *stack_a)
{
	t_list	*temp_node;

	//sa
	temp_node = stack_a;
	stack_a = stack_a->next;
	temp_node->next = stack_a->next;
	stack_a->next = temp_node;
}

void	rotate_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp_node;

	//ra
	temp_node = stack_a;
	stack_a = stack_a->next;
	temp_node->next = NULL;
	ft_lstlast(stack_a)->next = temp_node;
}

void	reverse_rotate_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp_node;

	//rra?
	ft_lstlast(stack_a)->next = temp_node;
	temp_node->next = NULL;
	stack_a = stack_a->next;
	temp_node = stack_a;
}
