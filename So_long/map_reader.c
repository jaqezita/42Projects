
#include "solong.h"


void	ft_create_matrix(char *path)
{
	int		fd;
	char	*lines;
	char	**map;
	char	*temp;

	fd = open(path, O_RDONLY);

	lines = get_next_line(fd);
	temp = " ";

	while (ft_strchr(lines, '\0') && temp != NULL)
	{
		temp = get_next_line(fd);
		lines = ft_strjoin(lines, temp);
	}
	map = ft_split(lines, '\n');
}

// void	check_stuff(char **map)
// {
// 	int i;
// 	int j;

// 	map[i][j];

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
// 				save position - exit;
// 				quant-exit ++;
// 			}
// 			if (map[i][j] == 'C')
// 			{
// 				save position - ligthning;
// 				quant-ligthning ++;
// 			}
// 			j += j + valor;
// 		}
// 		i+= i+ valor;
// 	}
// }

// void	ft_flood_fill(game_t coisas)
// {
// 	copy map[i][j];

// 	while (i < 1920)
// 	{
// 		while (j < 1080)
// 		{
// 			if (map[i][j] == '1')
// 				return;
// 			if (map[i][j] == '0')
// 			{
// 				map[i][j] = x;
// 			}
// 			if (map[i][j] == 'P')
// 			{
// 				return;
// 			}
// 			if (map[i][j] == 'C')
// 			{
// 				map[i][j] = 0;
// 			}
// 			if (map[i][j] == 'E')
// 			{
// 				return;
// 			}
// 			j += j + valor;
// 		}
// 		i+= i+ valor;
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
