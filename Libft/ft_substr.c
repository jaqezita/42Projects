/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:12:29 by jaqribei          #+#    #+#             */
/*   Updated: 2023/07/31 01:55:03 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	index;
	unsigned int	sub_index;
	char			*substr;

	substr = (char *)malloc((len + 1) * sizeof(char));
	index = 0;
	sub_index = start;
	if (!substr)
		return (NULL);
	while (s[index] != '\0' && sub_index < len)
	{
		substr[sub_index] = s[index];
		index++;
		sub_index++;
	}
	substr[sub_index] = '\0';
	return (substr);
}

/* #include <stdio.h>

int	main(void)
{
	printf("%s", ft_substr("Blackpink In Your Area", 5, 8));
	return (0);
} */

