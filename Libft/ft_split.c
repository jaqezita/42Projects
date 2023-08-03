/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:13:15 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/02 20:54:38 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	size_t	index;
	size_t	aux;
	size_t	aux1;
	char	**str;


	index = 0;
	str = malloc (ft_strlen(s) + 2 * (sizeof(char)));
	while (s[index] != '\0')
	{
		if (s[index] == c)
			break ;
		index++;
	}
	aux1 = index;
	aux = 0;
	while (index > 0)
	{
		str[1][aux] = s[index];
		index--;
		aux++;
	}
	aux = 0;
	while (aux1 < ft_strlen(s))
	{
		str[2][aux] = s[aux1];
		aux++;
		aux1--;
	}
	return(str);
}
