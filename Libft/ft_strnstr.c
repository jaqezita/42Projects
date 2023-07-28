/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:04:25 by jaqribei          #+#    #+#             */
/*   Updated: 2023/07/27 21:00:04 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	char	*big_copy;
	char	*little_copy;

	big_copy = (char *)big;
	little_copy = (char *)little;

	index = 0;
	len = ft_strlen(little);
	if (little ==  NULL || len == 0)
		return (big_copy);
	while (big[index] != '\0')
	{
		if ((big)[index] == (little)[len])
		{
			return (big_copy +index);
			index++;
		}
		else
			return (NULL);
	}
	return (little_copy);
}




/*
DESCRIPTION
     The strnstr() function locates the first occurrence of the null-terminated string little in the
     string big, where not more than len characters are searched.  Characters that appear after a ‘\0’
     character are not searched.  Since the strnstr() function is a FreeBSD specific API, it should
     only be used when portability is not a concern.

RETURN VALUES
     If little is an empty string, big is returned; if little occurs nowhere in big, NULL is returned;
     otherwise a pointer to the first character of the first occurrence of little is returned.

EXAMPLES
     The following sets the pointer ptr to NULL, because only the first 4 characters of largestring
     are searched:

           const char *largestring = "Foo Bar Baz";
           const char *smallstring = "Bar";
           char *ptr;

           ptr = strnstr(largestring, smallstring, 4);
*/
