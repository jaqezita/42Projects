/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:02:12 by jaqribei          #+#    #+#             */
/*   Updated: 2023/07/26 14:29:03 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{

	unsigned char	*buffer;
	unsigned char	*src_copy;
	unsigned char	*dest_copy;
	size_t			index;
	
	src_copy =	(unsigned char *)src;
	dest_copy = (unsigned char *)dest;
	buffer = src_copy;
	index = 0;
	//overlap treating need
	if (!dest_copy && !buffer)
		return (0);
	while (index < n)
	{
		dest_copy[index] = buffer[index];
		index++;
	}
	return (dest_copy);
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
