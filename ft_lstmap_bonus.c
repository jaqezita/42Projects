/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:05:30 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/07 02:40:55 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap_bonus(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*aux;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new = ft_lstnew_bonus(f(lst->content));
	if (new == NULL)
	{
		return (NULL);
	}
	aux = new;
	while (lst->next != NULL)
	{
		new->next = ft_lstnew_bonus(f(lst->next->content));
		if (new->next == NULL)
		{
			ft_lstclear_bonus(&aux, del);
			return (NULL);
		}
		lst = lst->next;
		new = new->next;
	}
	return (aux);
}
