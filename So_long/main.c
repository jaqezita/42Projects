/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:28:05 by jaqribei          #+#    #+#             */
/*   Updated: 2023/09/27 18:42:20 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int	i;
	int	j;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "f*");
	i = 0;
	while (i < 600)
	{
		j = 0;
		while (j < 600)
		{
				mlx_pixel_put(mlx, mlx_win, i, j, 0xFFFFFFFF);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
}
