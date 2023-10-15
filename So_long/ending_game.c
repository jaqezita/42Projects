/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 03:24:47 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/15 03:33:45 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game **game)
{
	int	percy_x;
	int	percy_y;
	int	portal_x;
	int	portal_y;

	percy_x = (*game)->load->percy->instances[0].x;
	percy_y = (*game)->load->percy->instances[0].y;
	portal_y = (*game)->load->portal->instances[0].x;
	portal_x = (*game)->load->portal->instances[0].y;
	if ((*game)->count->collected == (*game)->load->bolt->count)
		(*game)->load->portal->enabled = true;
	if ((percy_x > portal_x && percy_y > portal_y)
		&& percy_x < portal_x && percy_y < portal_y
		&& (*game)->load->portal->enabled == true)
		mlx_close_window((*game)->mlx);
}
