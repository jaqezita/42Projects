/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:28:05 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/13 05:51:23 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("%s\n", mlx_strerror(MLX_INVFILE));
		return (1);
	}
	game = ft_calloc(1, sizeof(t_game));
	game->load = ft_calloc(1, sizeof(t_assets));
	ft_create_matrix(argv[1], &game);
	ft_load_assets(&game);
	ft_place_assets(&game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	// ft_mechanisms(mlx);
	ft_free_load(&game);
	ft_free_struct(&game);
	return (0);
}
