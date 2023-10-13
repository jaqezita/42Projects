/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:09:18 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/13 19:38:49 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_load(t_game **game)
{
	mlx_delete_texture((*game)->load->t_bolt);
	mlx_delete_image((*game)->mlx, (*game)->load->bolt);
	mlx_delete_texture((*game)->load->t_percy);
	mlx_delete_image((*game)->mlx, (*game)->load->percy);
	mlx_delete_texture((*game)->load->t_enemy);
	mlx_delete_image((*game)->mlx, (*game)->load->enemy);
	mlx_delete_texture((*game)->load->t_tree);
	mlx_delete_image((*game)->mlx, (*game)->load->tree);
	mlx_delete_texture((*game)->load->t_bg);
	mlx_delete_image((*game)->mlx, (*game)->load->bg);
	mlx_delete_texture((*game)->load->t_portal);
	mlx_delete_image((*game)->mlx, (*game)->load->portal);
}

void	ft_free_struct(t_game **game)
{
	int	i;

	i = 0;
	free((*game)->load);
	free((*game)->count);
	while (i < (*game)->len)
	{
		free((*game)->map[i]);
		i++;
	}
	free((*game)->map);
	free(*game);
}