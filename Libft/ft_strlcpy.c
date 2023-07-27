/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:02:27 by jaqribei          #+#    #+#             */
/*   Updated: 2023/07/27 20:11:06 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	index;

	len = 0;
	index = 0;
	while (src[len])
	{
		len++;
	}
	if (size < 1)
	{
		return (len);
	}
	while (src[index] != '\0' && index < (size - 1))
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (len);
}

/* #include <stdio.h>

int	main(void)
{
	char		str[] = "Blackpink";
	char		dest[0];
	size_t		size = 3;

	printf("%zu\n", ft_strlcpy(dest, str, size));
} */
