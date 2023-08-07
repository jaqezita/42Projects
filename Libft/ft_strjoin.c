/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:12:44 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/07 01:29:29 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
cd ..
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index_suf;
	int		index;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	index_suf = 0;
	index = 0;
	while (s1[index] != '\0')
	{
			result[index] = s1[index];
			index++;
	}
	while (s2[index_suf] != '\0')
	{
			result[index] = s2[index_suf];
			index++;
			index_suf++;
	}
	result[index] = '\0';
	return (result);
}

/*
#include <stdio.h>
int     main(void)
{
        char    *ptr;

        ptr = ft_strjoin("black", "pink");

        printf("%s\n", ptr);
        return (0);
}*/
