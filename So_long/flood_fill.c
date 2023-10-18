/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:35:28 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/18 19:54:00 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(t_game **game, int x, int y)
{
	if ((*game)->map_copy[y][x] == '1' || (*game)->map_copy[y][x] == '#')
		return ;
	(*game)->map_copy[y][x] = '#';
	ft_flood_fill(game, x + 1, y);
	ft_flood_fill(game, x - 1, y);
	ft_flood_fill(game, x, y + 1);
	ft_flood_fill(game, x, y - 1);
}
