/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:35:28 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/18 18:55:40 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(t_game **game, int x, int y)
{
	if (x >= 0 && y >= 0 && x < (*game)->map[x][y] && y < (*game)->map[x][y])
	{
		if ((*game)->map_copy[x][y] == '1' || (*game)->map_copy[x][y] == '#' \
		|| (*game)->map_copy[x][y] == 'E' || (*game)->map_copy[x][y] == 'C')
			return ;
		else if ((*game)->map_copy[x][y] == '0')
			(*game)->map_copy[x][y] = '#';
		else if ((*game)->map_copy[x][y] == 'C')
		{
			(*game)->map[y][x] = '0';
		}
		else if ((*game)->map_copy[x][y] == 'E')
		{
			(*game)->map[y][x] = 'E';
			(*game)->count->exit = true;
		}
		ft_flood_fill(game, x + 1, y);
		ft_flood_fill(game, x - 1, y);
		ft_flood_fill(game, x, y + 1);
		ft_flood_fill(game, x, y - 1);
	}
}
