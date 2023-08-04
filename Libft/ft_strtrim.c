/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:13:03 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/03 18:39:07 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	// Sentido ->
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]))
			i++;
		else
			break ;
	}
	// Sentido <-
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[j]))
			j--;
		else
			break ;
	}
	// Monta string
	return (ft_substr(s1, i, (j - i + 1)));
}

/* #include<stdio.h>

int main (void)
{
        char    *ptr;

        ptr = ft_strtrim("abc   hello, world   ", "bcd");

        printf("%s", ptr);
        return (0);
} */