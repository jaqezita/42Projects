/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:28:05 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/23 21:55:27 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
		exit(ft_printf("Error\n%s\n", mlx_strerror(MLX_INVFILE)));
	if (!argv[1])
		exit(ft_printf("Error\n%s\n", mlx_strerror(MLX_INVFILE)));
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
