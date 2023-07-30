/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:04:25 by jaqribei          #+#    #+#             */
/*   Updated: 2023/07/30 19:29:26 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index_b;
	size_t	index_l;

	index_b = 0;
	if (*little ==  0)
		return ((char *)big);
	while (index_b < len && big[index_b] != '\0')
	{
		if (big[index_b] == little[0])
		{
			index_l = 0;
			while (big[index_b + index_l] == little[index_l] && (index_b + index_l < len))
			{
				if (little[index_l + 1] == '\0')
					return ((char *)&big[index_b]);
				index_l++;
			}
		}
		index_b++;
	}
	return (NULL);
}

/* #include <stdio.h>
int	main(void)
{
//        	const char *largestring = "Foo Bar Baz";
//       const char *smallstring = "Bar";
//        char *ptr; 


	
	printf ("%s\n", ft_strnstr("Foo Bar Baz", "Bar", 7));
	return (0); 
} */
