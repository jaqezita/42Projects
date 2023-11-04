/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:57:17 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/04 10:39:35 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_node;

	//pa
	if (*stack_a)
	{
		temp_node = *stack_a;
		*stack_a = (*stack_a)->next;
		temp_node->next = *stack_b;
		*stack_b = temp_node;
	}
}

void	swap_a(t_list **stack_a)
{
	t_list	*temp_node;

	//sa
	if (*stack_a && (*stack_a)->next)
	{
		temp_node = *stack_a;
		*stack_a = (*stack_a)->next;
		temp_node->next = (*stack_a)->next;
		(*stack_a)->next = temp_node;
	}
}

void	rotate_a(t_list **stack_a)
{
	t_list	*temp_node;

	//ra
	if (*stack_a && (*stack_a)->next)
	{
		temp_node = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_lstlast(*stack_a)->next = temp_node;
		temp_node->next = NULL;
	}
}

void	reverse_rotate_a(t_list **stack_a)
{
	t_list	*temp_node;
	t_list	*aux;
	
	//rra?
	temp_node = ft_lstlast(*stack_a);
	aux	= *stack_a;
	while (aux->next != temp_node)
	{
		aux = aux->next;
	}
	aux->next = NULL;
	temp_node->next = *stack_a;
	(*stack_a) = temp_node;
}
