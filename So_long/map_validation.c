/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:35:48 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/18 18:56:44 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_ok(t_game **game)
{
	validate_square_map(game);
	validate_map(game, 0, 0);
	ft_validate_characteres(game, 0, 0);
	count_characters(game, 0, 0);
}

void	ft_up(t_game **game)
{
	(*game)->load->percy->instances[0].y -= 75;
	(*game)->count->steps++;
	ft_printf("Steps: %d\n", (*game)->count->steps);
}

void	ft_down(t_game **game)
{
	(*game)->load->percy->instances[0].y += 75;
	(*game)->count->steps++;
	ft_printf("Steps: %d\n", (*game)->count->steps);
}

void	ft_left(t_game **game)
{
	(*game)->load->percy->instances[0].x -= 75;
	(*game)->count->steps++;
	ft_printf("Steps: %d\n", (*game)->count->steps);
}

void	ft_right(t_game **game)
{
	(*game)->load->percy->instances[0].x += 75;
	(*game)->count->steps++;
	ft_printf("Steps: %d\n", (*game)->count->steps);
}
