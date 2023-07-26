/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:11:36 by jaqribei          #+#    #+#             */
/*   Updated: 2023/07/24 21:42:12 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		((unsigned char *)s)[index] = 0;
		index++;
	}
}

/* void	ft_bzero(void *s, size_t n)
{
	size_t	index;
	unsigned char *s_copy;
	
	index = 0;
	s_copy = s;
	while (index < n)
	{
		s_copy[index] = 0;
		index++;
	}
} */

/* #include <stdio.h>
//#include <string.h>
  
int main()
{
	
	
    char str[50] = "GeeksForGeeks is for programming geeks.";
    printf("\nBefore memset(): %s\n", str);
  
    // Fill 8 characters starting from str[13] with '.'
    bzero(str + 13, 8*sizeof(char));
  
    printf("After ft_memset():  %s", str);
    return 0;
}

//Before memset(): GeeksForGeeks is for programming geeks.
//After memset(): GeeksForGeeks........programming geeks.
 */