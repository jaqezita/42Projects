/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:29:40 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/23 19:59:49 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_invalid_type(char *path, t_game **game)
{
	if (ft_strncmp(&path[ft_strlen(path) - 4], ".ber", 4) != 0)
	{
		ft_free_struct(game);
		exit(ft_printf("Error\n%s", "INVALID MAP"));
	}
}

void	ft_message(t_game **game)
{
	ft_free_struct(game);
	exit(ft_printf("Error\n%s", "INVALID MAP"));
}

void	collision(t_game **game)
{
	size_t			i;
	unsigned int	enemy_x;
	unsigned int	enemy_y;
	unsigned int	percy_x;
	unsigned int	percy_y;

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
		{
			ft_free_load(game);
			mlx_terminate((*game)->mlx);
			ft_free_struct(game);
			exit((ft_printf("%s\n", "GAME OVER")));
		}
		i++;
	}
}
