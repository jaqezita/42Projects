/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:04:25 by jaqribei          #+#    #+#             */
/*   Updated: 2023/07/30 20:40:27 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	b = 0;
	if (*little == 0)
		return ((char *)big);
	while (b < len && big[b] != '\0')
	{
		if (big[b] == little[0])
		{
			l = 0;
			while (big[b + l] == little[l] && (b + l < len))
			{
				if (little[l + 1] == '\0')
					return ((char *)&big[b]);
				l++;
			}
		}
		b++;
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
