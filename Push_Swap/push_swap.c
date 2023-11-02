/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:34:39 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/02 20:33:22 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		index;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*new_node;
	t_list	*current;
	int		*arg_value;
	t_list	*temp_node;

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
	current = stack_a;
	while (current)
	{
		ft_printf("%d\n", *(int *)(current->content));
		current = current->next;
	}
	// push a
	temp_node = stack_a;
	stack_a = stack_a->next;
	temp_node->next = stack_b;
	stack_b = temp_node;

	// push b
	temp_node = stack_b;
	stack_b = stack_b->next;
	temp_node->next = stack_a;
	stack_a = temp_node;
	
	// swap a
	temp_node = stack_a;
	stack_a = stack_a->next;
	temp_node->next = stack_a->next;
	stack_a->next = temp_node;

	// swap b
	temp_node = stack_b;
	stack_b = stack_b->next;
	temp_node->next = stack_b->next;
	stack_b->next = temp_node;
	
	// rotate a
	temp_node = stack_a;
	stack_a = ft_lstlast(stack_a);
	temp_node->next = NULL; 
	

	// rotate b

	// reverse rotate a

	// reverse rotate b

	ft_lstclear(&stack_a, free);
	return (0);
}
