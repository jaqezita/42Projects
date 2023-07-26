/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:03:55 by jaqribei          #+#    #+#             */
/*   Updated: 2023/07/26 14:55:10 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		index;
	unsigned char	*s_copy;

	s_copy = (unsigned char *)s;
	index = 0;
	while (index <= n)
	{
		if (s_copy[index] == (unsigned char)c)
			return (s_copy[index]);
		index++; 
	}
	return (0);
}
