/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:03:22 by jaqribei          #+#    #+#             */
/*   Updated: 2023/07/27 15:05:27 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_strchr(const char *s, int c)
{
	int	index;
	char	*s_copy;

	s_copy = (char *)s;
	index = 0;
	while (s_copy[index])
	{
		if (s_copy[index] == c)
			return (&s_copy[index]);
		index++;
	}
	return (0);
}
