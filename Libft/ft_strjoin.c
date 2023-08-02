/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:12:44 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/02 11:47:32 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index_pre;
	int		index_suf;
	int		index;
	char	*result;

	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	index_pre = 0;
	index_suf = 0;
	index = 0;
	if (!result)
		return (NULL);
	while (s1[index_pre] != '\0')
	{
			result[index] = s1[index_pre];
			index++;
			index_pre++;
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