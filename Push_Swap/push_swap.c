/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:34:39 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/04 11:01:47 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		index;
	int		*arg_value;
	t_list	*stack_a;
	t_list	*new_node;
	int		index2;

	stack_a = NULL;
	check_errors(argc, argv);
	index = 1;
	while (index < argc)
	{
		arg_value = (int *)malloc(sizeof(int));
		*arg_value = ft_atoi(argv[index]);
		new_node = ft_lstnew(arg_value);
		ft_lstadd_back(&stack_a, new_node);
		index++;
	}
	print_stack(&stack_a);
	while (index2 < ft_lstsize)
	{
		if (*(int *)stack_a->content % 2 == 0)
			rotate_a(&stack_a);
		else
			push_b(&stack_a);
	}
	
	write (1, "\n", 1);
	print_stack(&stack_a);
	ft_lstclear(&stack_a, free);
	return (0);
}

// void	populate/create_stack(int argc, char *argv[])
// {
// }