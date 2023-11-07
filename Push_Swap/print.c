/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:44:34 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/07 20:48:42 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node **stack_a)
{
	t_node	*current;

	current = *stack_a;
	while (current)
	{
		ft_printf("%d : index %d \n", (current->content), current->index);
		current = current->next;
	}
}
