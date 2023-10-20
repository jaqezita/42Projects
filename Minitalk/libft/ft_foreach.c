/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:56:09 by jaqribei          #+#    #+#             */
/*   Updated: 2023/07/19 20:01:01 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int lenght, void (*f)(int))
{
	int	index;

	index = 0;
	while (index < lenght)
	{
		f(tab[index]);
		index++;
	}
}
