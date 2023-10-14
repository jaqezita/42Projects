/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:28:05 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/13 21:46:50 by jaqribei         ###   ########.fr       */
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
	game->count = ft_calloc(1, sizeof(t_count));
	ft_create_matrix(argv[1], &game);
	if(validate_square_map(&game))
		ft_printf("ok\n");
	else
		ft_printf("not ok\n");
	if (validate_map(&game, 0, 0))
		ft_printf("ok\n");
	else
		ft_printf("not ok\n");
	if(ft_validate_characteres(&game, 0, 0))
		ft_printf("ok\n");
	else
		ft_printf("not ok\n");
	if(count_characters(&game, 0, 0))
		ft_printf("ok\n");
	else
		ft_printf("not ok\n");
	ft_load_assets(&game);
	ft_place_assets(&game, 0, 0);
	mlx_loop(game->mlx);
	ft_free_load(&game);
	mlx_terminate(game->mlx);
	// ft_mechanisms(mlx);
	ft_free_struct(&game);
	return (0);
}
