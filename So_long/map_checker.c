/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 05:48:14 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/13 05:48:35 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_matrix(char *path, t_game **game)
{
	int		fd;
	char	*lines;
	char	*temp;

	fd = open(path, O_RDONLY);
	lines = get_next_line(fd);
	temp = " ";
	(*game)->len = 0;
	while (ft_strchr(lines, '\0') && temp != NULL)
	{
		temp = get_next_line(fd);
		(*game)->len++;
		lines = ft_strjoin(lines, temp);
	}
	(*game)->map = ft_split(lines, '\n');
}

// void	check_stuff(char **map)
// {
// 	int i
// 	int j;
// 	t_game *map;

// 	map[i][j]; //needs memory allocation (need to know, the array size)

// 	while (i < 1920)
// 	{
// 		while (j < 1080)
// 		{
// 			if (map[i][j] == '1')
// 				edges;
// 			if (map[i][j] == 'P')
// 			{
// 				save position - player;
// 				quant-player ++;
// 			}
// 			if (map[i][j] == 'E')
// 			{
// 				quant-exit ++;
// 			}
// 			if (map[i][j] == 'C')
// 			{
// 				quant-ligthning ++;
// 			}
// 			j += valor;
// 		}
// 		i += valor;
// 	}
// }

// void	ft_flood_fill(game_t coisas)
// {
// 	copy map[i][j];

// 			if (map[i][j] == '1')
// 				return;
// 			else if (map[i][j] == '0')
// 			{
// 				map[i][j] = x;
// 			}
// 			else if (map[i][j] == 'P')
// 			{
// 				return;
// 			}
// 			else if (map[i][j] == 'C')
// 			{
// 				map[i][j] = 0;
// 			}
// 			else if (map[i][j] == 'E')
// 			{
// 				return;
// 			}
			// ft_flood_fill()

// 	}
// }

// // void	ft_put_stuff(game_t)
// // {
// // 	int i;
// // 	int j;

// // 	map[i][j];

// // 	while (i < 1920)
// // 	{
// // 		while (j < 1080)
// // 		{
// // 			if (map[i][j] == '1')
// // 				put wall;
// // 				texture = mlx_load_png("bg.png");
// // 				img = mlx_texture_to_image(mlx, texture);
// // 				mlx_image_to_window(mlx, img, 0, 0);
// // 			if (map[i][j] == 'P')
// // 			{
// // 				put player;
// // 				texture = mlx_load_png("bg.png");
// // 				img = mlx_texture_to_image(mlx, texture);
// // 				mlx_image_to_window(mlx, img, 0, 0);
// // 			}
// // 			if (map[i][j] == 'E')
// // 			{
// // 				put exit;
// // 				texture = mlx_load_png("bg.png");
// // 				img = mlx_texture_to_image(mlx, texture);
// // 				mlx_image_to_window(mlx, img, 0, 0);
// // 			}
// // 			if (map[i][j] == 'C')
// // 			{
// // 				put lighting
// // 				texture = mlx_load_png("bg.png");
// // 				img = mlx_texture_to_image(mlx, texture);
// // 				mlx_image_to_window(mlx, img, 0, 0);
// // 			}	
// // 			j += j + valor;	
// // 		}
// // 		i+= i+ valor;	
// // 	}
// // }
