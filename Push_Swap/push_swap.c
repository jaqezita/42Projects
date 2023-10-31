/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 05:34:39 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/31 07:54:19 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		index;
	t_list	*stack_a;
	t_list	*node;
	t_list	*stack_b;
	t_list	*current;
	int		*teste;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (argv == NULL)
		return (0);
	index = 1;
	while (index < argc)
	{
		teste = (int *)malloc(sizeof(int));
		*teste = ft_atoi(argv[index]);
		node = ft_lstnew(teste);
		ft_lstadd_back(&stack_a, node);
		index++;
	}
	current = stack_a;
	while (current)
	{
		ft_printf("%d\n", *(int *)(current->content));
		current = current->next;
	}
	return (0);
}
