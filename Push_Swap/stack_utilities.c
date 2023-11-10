/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:31:43 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/07 21:06:24 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	max_index(t_node **stack_a)
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
