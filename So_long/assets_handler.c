/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:07:17 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/18 18:55:07 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_assets(t_game **game)
{
	(*game)->mlx = mlx_init(ft_strlen((*game)->map[0]) * WALL_SIZE, \
		(*game)->len * WALL_SIZE, "The Lightning Thief", 0);
	(*game)->load->t_bolt = mlx_load_png("./assets/bolt/4.png");
	(*game)->load->bolt = mlx_texture_to_image((*game)->mlx, \
		(*game)->load->t_bolt);
	(*game)->load->t_percy = mlx_load_png("./assets/percy.png");
	(*game)->load->percy = mlx_texture_to_image((*game)->mlx, \
	(*game)->load->t_percy);
	(*game)->load->t_enemy = mlx_load_png("./assets/enemy.png");
	(*game)->load->enemy = mlx_texture_to_image((*game)->mlx, \
		(*game)->load->t_enemy);
	(*game)->load->t_tree = mlx_load_png("./assets/tree.png");
	(*game)->load->tree = mlx_texture_to_image((*game)->mlx, \
		(*game)->load->t_tree);
	(*game)->load->t_bg = mlx_load_png("./assets/bg.png");
	(*game)->load->bg = mlx_texture_to_image((*game)->mlx, \
		(*game)->load->t_bg);
	(*game)->load->t_portal = mlx_load_png("./assets/portal.png");
	(*game)->load->portal = mlx_texture_to_image((*game)->mlx, \
		(*game)->load->t_portal);
}

void	ft_place_assets(t_game **game, int x, int y)
{
	mlx_image_to_window((*game)->mlx, (*game)->load->bg, y, x);
	ft_check_place(game, (*game)->load, x, y);
	(*game)->load->portal->enabled = false;
}

void	ft_check_place(t_game **game, t_assets *load, int y, int x)
{
	size_t	i;
	size_t	j;

	i = 0;
	x = 0;
	while (i < (*game)->len)
	{
		y = 0;
		j = 0;
		while (j <= ft_strlen((*game)->map[i]))
		{
			if ((*game)->map[i][j] == '1')
				mlx_image_to_window((*game)->mlx, (*game)->load->tree, y, x);
			else if ((*game)->map[i][j] == 'P')
				mlx_image_to_window((*game)->mlx, (*game)->load->percy, y + 10, x + 7);
			else if ((*game)->map[i][j] == 'E')
				mlx_image_to_window((*game)->mlx, (*game)->load->portal, y + 5, x + 5);
			else if ((*game)->map[i][j] == 'C')
				mlx_image_to_window((*game)->mlx, (*game)->load->bolt, y + 13, x + 15);
			j++;
			y += 75;
		}
		i++;
		x += 75;
	}
}
