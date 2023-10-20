/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_handler_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:07:17 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/20 08:15:47 by jaqribei         ###   ########.fr       */
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
	(*game)->load->t_icon = mlx_load_png("./assets/icon.png");
	(*game)->load->t_enemy = mlx_load_png("./assets/enemy.png");
	(*game)->load->enemy = mlx_texture_to_image((*game)->mlx, \
		(*game)->load->t_enemy);
}

void	ft_place_assets(t_game **game, int x, int y)
{
	mlx_image_to_window((*game)->mlx, (*game)->load->bg, y, x);
	ft_check_place(game, (*game)->load, x, y);
	ft_check_place2(game, (*game)->load, x, y);
	(*game)->load->portal->enabled = false;
	mlx_set_icon((*game)->mlx, (*game)->load->t_icon);
}

void	ft_check_place(t_game **game, t_assets *load, int y, int x)
{
	(*game)->i = 0;
	x = 0;
	while ((*game)->i < (*game)->len)
	{
		y = 0;
		(*game)->j = 0;
		while ((*game)->j <= ft_strlen((*game)->map[(*game)->i]))
		{
			if ((*game)->map[(*game)->i][(*game)->j] == '1')
				mlx_image_to_window((*game)->mlx, (*game)->load->tree, y, x);
			else if ((*game)->map[(*game)->i][(*game)->j] == 'P')
				mlx_image_to_window((*game)->mlx, \
				(*game)->load->percy, y + 10, x + 7);
			else if ((*game)->map[(*game)->i][(*game)->j] == 'E')
				mlx_image_to_window((*game)->mlx, \
				(*game)->load->portal, y + 5, x + 5);
			else if ((*game)->map[(*game)->i][(*game)->j] == 'C')
				mlx_image_to_window((*game)->mlx, \
				(*game)->load->bolt, y + 13, x + 15);
			(*game)->j++;
			y += 75;
		}
		(*game)->i++;
		x += 75;
	}
}

void	ft_check_place2(t_game **game, t_assets *load, int y, int x)
{
	(*game)->i = 0;
	x = 0;
	while ((*game)->i < (*game)->len)
	{
		y = 0;
		(*game)->j = 0;
		while ((*game)->j <= ft_strlen((*game)->map[(*game)->i]))
		{
			if ((*game)->map[(*game)->i][(*game)->j] == 'M')
				mlx_image_to_window((*game)->mlx, \
				(*game)->load->enemy,  y + 13, x + 15);
			(*game)->j++;
			y += 75;
		}
		(*game)->i++;
		x += 75;
	}
}

void	exit_game(t_game **game)
{
	int	percy_x;
	int	percy_y;
	int	portal_x;
	int	portal_y;

	percy_x = (*game)->load->percy->instances->x;
	percy_y = (*game)->load->percy->instances->y;
	portal_y = (*game)->load->portal->instances->y;
	portal_x = (*game)->load->portal->instances->x;
	if ((*game)->count->collected == (*game)->load->bolt->count)
		(*game)->load->portal->enabled = true;
	if ((*game)->load->portal->enabled == true \
		&& (percy_x > portal_x && percy_y > portal_y) \
		&& (percy_x < portal_x + (*game)->load->portal->width \
		&& percy_y < portal_y + (*game)->load->portal->height))
	{
		ft_printf("You won!\n");
		exit(EXIT_SUCCESS);
	}
}

void	ft_flood_fill(t_game **game, int x, int y)
{
	if ((*game)->map_copy[y][x] == 'C')
		(*game)->count->coin--;
	if ((*game)->map_copy[y][x] == '1' || (*game)->map_copy[y][x] == '#')
		return ;
	(*game)->map_copy[y][x] = '#';
	ft_flood_fill(game, x + 1, y);
	ft_flood_fill(game, x - 1, y);
	ft_flood_fill(game, x, y + 1);
	ft_flood_fill(game, x, y - 1);
}
