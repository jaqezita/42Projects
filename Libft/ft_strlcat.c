/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:02:43 by jaqribei          #+#    #+#             */
/*   Updated: 2023/07/27 20:09:18 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	len;
	size_t	result;

	index = 0;
	len = ft_strlen(dst);
	result = (ft_strlen(dst) + ft_strlen(src));
	if (size > len)
	{
		while (src[index] && len < (size - 1))
		{
			dst[len] = src[index];
			len++;
			index++;
		}
		dst[len] = '\0';
		return (result);
	}
	return (ft_strlen(src) + size);
}

/*  #include <stdio.h>

int	main(void)
{
	char		str[] = "Blackpink";
	char		dest[] = " In Your Area"; 
	size_t		size = 3;

	printf("%zu\n", ft_strlcat(dest, str, size));
}
 */