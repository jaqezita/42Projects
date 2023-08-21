/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:20:52 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/21 01:19:01 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	len;

	len = 0;
	while (s != NULL && s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index_suf;
	int		index;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	result = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!result)
		return (NULL);
	index_suf = 0;
	index = 0;
	while (s1 != NULL && s1[index] != '\0')
	{
			result[index] = s1[index];
			index++;
	}
	while (s2 != NULL && s2[index_suf] != '\0')
	{
			result[index] = s2[index_suf];
			index++;
			index_suf++;
	}
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	char	*s_copy;

	s_copy = (char *)s;
	while (s_copy != NULL && *s_copy)
	{
		if (*s_copy == (char)c)
			return (s_copy);
		s_copy++;
	}
	if ((unsigned char)c == '\0')
		return (s_copy);
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;
	int		result;

	pointer = NULL;
	result = nmemb * size;
	if (!nmemb || !size || nmemb == result / size)
		pointer = malloc(result);
	if (pointer)
		while (result--)
			*(unsigned char *)(pointer + result) = 0;
	return (pointer);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	index;
	char			*substr;
	char			*str;

	index = 0;
	str = "\0";
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (str);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = ft_calloc((len + 1), sizeof(char));
	if (!substr)
		return (NULL);
	while (s[start] != '\0' && index < len)
	{
		substr[index] = s[start];
		start++;
		index++;
	}
	return (substr);
}
