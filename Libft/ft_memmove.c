/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:02:12 by jaqribei          #+#    #+#             */
/*   Updated: 2023/07/27 13:51:35 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	if (src > dest)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
	}
	return (dest);
}

/* //A C program to demonstrate working of memmove 
#include <stdio.h>
#include <string.h>
 
int main()
{
	char str1[9] = "Abacate"; // Array of size 100
//    char str2[] = "Quiz"; // Array of size 5
 
	puts("str1 before memmove ");
	puts(str1);
//     Copies contents of str2 to sr1
	ft_memmove(str1 + 3, str1, sizeof(str1));
 
	puts("\nstr1 after memmove ");
	puts(str1);
 
	return 0;
}  */
