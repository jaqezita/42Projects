/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:37:19 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/10 13:08:28 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments\n");
		return (0);
	}
	game = malloc(sizeof(t_game));
	if (!game)
	{
		printf("Error\nMalloc failed\n");
		return (0);
	}
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		printf("Error\nMLX failed\n");
		return (0);
	}
	game->mlx_win = mlx_new_window(game->mlx, 512, 512, "Hello world!");
	if (!game->mlx_win)
	{
		printf("Error\nMLX window failed\n");
		return (0);
	}
	mlx_loop(game->mlx);
	return (0);
}

