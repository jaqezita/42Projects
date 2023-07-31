/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:04:44 by jaqribei          #+#    #+#             */
/*   Updated: 2023/07/30 21:39:45 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*calloc(size_t nmemb, size_t size)
{

	char	*new;

	new = (char *)nmemb;
	if (new == 0 || size == 0)
		return(NULL);
	if (nmemb * size > 2147483647)
		return (NULL);
	return (new);

}

