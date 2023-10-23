/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:29:40 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/23 19:43:36 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_invalid_type(char *path, t_game **game)
{
	if (ft_strncmp(&path[ft_strlen(path) - 4], ".ber", 4) != 0)
	{
		ft_message(game);
	}
}

void	ft_message(t_game **game)
{
	ft_free_struct(game);
	exit(ft_printf("Error\n%s\n", "INVALID MAP"));
}