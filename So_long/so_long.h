/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:05:43 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/13 21:40:38 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./MLX42/include/MLX42/MLX42.h"
# include "./libft/libft.h"

# define WALL_SIZE 75

typedef struct s_assets
{
	mlx_texture_t	*t_bolt;
	mlx_image_t		*bolt;
	mlx_texture_t	*t_percy;
	mlx_image_t		*percy;
	mlx_texture_t	*t_portal;
	mlx_image_t		*portal;
	mlx_texture_t	*t_tree;
	mlx_image_t		*tree;
	mlx_texture_t	*t_enemy;
	mlx_image_t		*enemy;	
	mlx_texture_t	*t_bg;
	mlx_image_t		*bg;
}					t_assets;

typedef struct s_count
{
	int	player;
	int	exit;
	int	coin;
}		t_count;

typedef struct s_game
{
	char		**map;
	char		**map_copy;
	mlx_t		*mlx;
	t_assets	*load;
	t_count		*count;
	size_t		len;
	size_t		x;
	size_t		y;
}				t_game;

void	ft_create_matrix(char *path, t_game **game);
void	ft_read_map(t_game **game);
// void	ft_check_map(char **str);
void	ft_load_assets(t_game **game);
void	ft_place_assets(t_game **game, int x, int y);
void	ft_free_load(t_game **game);
// void	ft_mechanisms(mlx stuff);
// void	ft_free(t_game allocate);
void	ft_free_struct(t_game **game);
int	validate_map(t_game **game, int x, int y);
int	validate_square_map(t_game **game);
int	ft_validate_characteres(t_game **game, int x, int y);
int	count_characters(t_game **game, int x, int y);

#endif
