/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:17:01 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/04 19:17:54 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*populate_stack(int argc, char *argv[])
{
	int		index;
	int		*arg_value;
	t_node	*stack_a;
	t_node	*new_node;

	stack_a = NULL;
	index = 1;
	while (index < argc)
	{
		arg_value = (int *)malloc(sizeof(int));
		*arg_value = ft_atoi(argv[index]);
		new_node = ft_lstnew(arg_value);
		ft_lstadd_back(&stack_a, new_node);
		index++;
	}
	return (stack_a);
}