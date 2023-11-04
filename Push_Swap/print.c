/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:44:34 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/04 05:18:48 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list **stack_a)
{
	t_list	*current;

	current = *stack_a;
	while (current)
	{
		ft_printf("%d\n", *(int *)(current->content));
		current = current->next;
	}
}
