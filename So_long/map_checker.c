/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 05:48:14 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/18 19:50:59 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_matrix(char *path, t_game **game)
{
	int		fd;
	char	*lines;
	char	*temp;
	char	*temp2;

	if (ft_strncmp(&path[ft_strlen(path) - 4], ".ber", 4) != 0)
		exit(ft_printf("Error:\n%s", mlx_strerror(MLX_INVEXT)));
	fd = open(path, O_RDONLY);
	lines = get_next_line(fd);
	temp = " ";
	(*game)->len = 0;
	while (ft_strchr(lines, '\0') && temp != NULL)
	{
		temp = get_next_line(fd);
		(*game)->len++;
		temp2 = lines;
		lines = ft_strjoin(lines, temp);
		free(temp2);
		free(temp);
	}
	(*game)->map = ft_split(lines, '\n');
	(*game)->map_copy = ft_split(lines, '\n');
	free(lines);
}

int	validate_map(t_game **game, int x, int y)
{
	y = 0;
	while (y < (*game)->len)
	{
		x = 0;
		while (x < ft_strlen((*game)->map[0]))
		{
			if ((x >= 0 && x < ft_strlen((*game)->map[0])) \
			&& (y == 0 || y == (*game)->len - 1))
			{
				if ((*game)->map[y][x] != '1')
					exit(ft_printf("Error\n%s", "INVALID MAP"));
			}
			else if ((x == 0 || x == ft_strlen((*game)->map[0]) - 1) \
			&& (y > 0 || y < (*game)->len - 1))
			{
				if ((*game)->map[y][x] != '1')
					exit(ft_printf("Error\n%s", "INVALID MAP"));
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	validate_square_map(t_game **game)
{
	if (ft_strlen((*game)->map[0]) == (*game)->len)
		exit(ft_printf("Error\n%s", "INVALID MAP"));
	return (1);
}

int	ft_validate_characteres(t_game **game, int x, int y)
{
	y = 0;
	while (y < (*game)->len)
	{
		x = 0;
		while (x < ft_strlen((*game)->map[0]))
		{
			if (!ft_strchr("PEC10", (*game)->map[y][x]))
			{
				ft_printf("Error\n%s", "INVALID MAP");
				exit(EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	count_characters(t_game **game, int x, int y)
{
	y = 0;
	while (y < (*game)->len)
	{
		x = 0;
		while (x < ft_strlen((*game)->map[0]))
		{
			if ((*game)->map[y][x] == 'P')
			{
				(*game)->count->player++;
				(*game)->pos_x1 = x;
				(*game)->pos_y1 = y;
			}
			else if ((*game)->map[y][x] == 'E')
				(*game)->count->exit++;
			else if ((*game)->map[y][x] == 'C')
				(*game)->count->coin++;
			x++;
		}
		y++;
	}
	if ((*game)->count->player != 1 || (*game)->count->exit != 1 \
	|| (*game)->count->coin < 1)
		exit(EXIT_FAILURE);
}
