/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:12:29 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/02 12:46:21 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	index;
	char			*substr;

	substr = malloc ((len + 1) * sizeof(char));
	index = 0;
	if (start >= ft_strlen(s))
	{
		substr[index] = '\0';
		return (substr);
	}
	if (!substr)
		return (NULL);
	while (s[start] != '\0' && index < len)
	{
		substr[index] = s[start];
		start++;
		index++;
	}
	substr[index] = '\0';
	return (substr);
}

/* #include <stdio.h>

int	main(void)
{
	printf("%s", ft_substr("Blackpink In Your Area", 5, 8));
	return (0);
} */
