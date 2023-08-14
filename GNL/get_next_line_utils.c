/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:20:52 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/14 05:33:49 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		write(fd, &s[index], 1);
		index++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	char	*s_copy;

	s_copy = (char *)s;
	while (*s_copy)
	{
		if (*s_copy == (char)c)
			return (s_copy);
		s_copy++;
	}
	if ((unsigned char)c == '\0')
		return (s_copy);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	index;
	char			*substr;

	index = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = malloc ((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (s[start] != '\0' && index < len)
	{
		substr[index] = s[start];
		start++;
		index++;
	}
	substr[index] = '\0';
	return (substr);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	int		index;

	new = malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!new)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		new[index] = s[index];
		index++;
	}
	new[index] = '\0';
	return (new);
}
