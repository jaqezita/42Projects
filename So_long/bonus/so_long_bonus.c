/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:28:05 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/22 23:22:06 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Error\n%s", mlx_strerror(MLX_INVFILE));
		return (1);
	}
	game = ft_calloc(1, sizeof(t_game));
	game->load = ft_calloc(1, sizeof(t_assets));
	game->count = ft_calloc(1, sizeof(t_count));
	ft_create_matrix(argv[1], &game);
	map_ok(&game);
	ft_load_assets(&game);
	ft_place_assets(&game, 0, 0);
	ft_walk(&game);
	mlx_loop(game->mlx);
	ft_free_load(&game);
	mlx_terminate(game->mlx);
	ft_free_struct(&game);
	return (0);
}

void	collision(t_game **game)
{
	int	i;
	int	enemy_x;
	int	enemy_y;
	int	percy_x;
	int	percy_y;

	i = 0;
	percy_x = (*game)->load->percy->instances[0].x;
	percy_y = (*game)->load->percy->instances[0].y;
	while (i < (*game)->load->enemy->count)
	{
		enemy_x = (*game)->load->enemy->instances[i].x;
		enemy_y = (*game)->load->enemy->instances[i].y;
		if ((percy_x > enemy_x && percy_y > enemy_y) && (percy_y < enemy_y \
			+ (*game)->load->enemy->width && percy_x < enemy_x \
			+ (*game)->load->enemy->height))
			exit((ft_printf("%s\n", "GAME OVER")));
		i++;
	}
}
