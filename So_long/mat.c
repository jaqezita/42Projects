/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:28:05 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/10 01:06:20 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*Coda o seguinte: 

Matriz de nomes aleatórios;

Conta o tamanho de cada nome e quantas letras 'a' tem em cada nome.

Acho que isso vai te dar a noção de criar, percorrer e saber olhar os conteúdos desses array de array.

Vai ajudar a entender muito do rolê do jogo acontecendo também.*/

#include "includes/Libft/libft.h"

static int	ft_lenght(char const **s, char *c);
static int	ft_count_words(char const **s, char *c);

int	main(int argc, char *argv[])
{
	char	**mat;
	int		i;
	int		j;
	int		words;

	if (argc < 1)
		return (0);

	words = ft_count_words(**argv, ", ");
	
	mat = (char **)malloc((words + 1) * sizeof (char *));
	i = 0;
	while (i < argc)
	{
		while (*mat[i] != '\0')
		{
			j = 0;
			while (mat[i][j] != '\0')
			{
				write (1, &mat[i][j], 1);
				j++;
			}
			i++;
		}
		write (1, "\n", 1);
	}
		
	return (0);
}


static int	ft_count_words(char const **s, char *c)
{	
	int	index;
	int	words;
	int	len;
	int	j;

	index = 0;
	words = 0;
	len = ft_strlen(s);
	while (index < len)
	{
		if (s[index] == c)
			index++;
		else
		{
			while (s[j][index] != *c && s[j][index] != NULL)
			{
				index++;
			}
			words++;
		}
	}
	return (words);
}

static int	ft_lenght(char const **s, char *c)
{	
	int	index;
	int	lenght;
	int	len;
	int	j;

	index = 0;
	lenght = 0;
	len = ft_strlen(s);
	while (index < len)
	{
		if (s[index] == c)
			index++;
		else
		{
			while (s[j][index] != *c && s[j][index] != NULL)
			{
				index++;
				lenght++;
			}
			return (lenght);
		}
	}
	return (0);
}


