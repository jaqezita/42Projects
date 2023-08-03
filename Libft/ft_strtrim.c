/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:13:03 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/02 22:37:58 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

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
	str = malloc(ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	str = ft_substr(s1, i, (j - i + 1));
	return (str);
}

/* #include<stdio.h>

int main (void)
{
        char    *ptr;

        ptr = ft_strtrim("abc   hello, world   ", "bcd");

        printf("%s", ptr);
        return (0);
} */