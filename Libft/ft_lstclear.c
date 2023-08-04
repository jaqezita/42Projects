/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:04:47 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/04 18:13:23 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void(*del)(void *))
{
	t_list	*aux;
	t_list	*current;

	if (lst == NULL || del == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{	
		aux = current->next;
		del(current->content);
		free(current);
		current = aux;
	}
	*lst = NULL;
}
