/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:28:05 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/12 04:46:00 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "solong.h"

int main(int argc, char *argv[])
{
	mlx_t		*mlx;
	int32_t		width;
	int32_t		height;
	mlx_image_t	*img;
	mlx_texture_t *texture;
	
	width = 512;
	height = 512;
	texture = mlx_load_png("bg.png");
	
	if (argc != 2)
	{
		ft_printf("%s\n", mlx_strerror(MLX_INVFILE));
		return(1);
	}
	
	ft_create_matrix(argv[1]);
	
	mlx = mlx_init(width, height, "The Lightning Thief", true);
	
	img = mlx_texture_to_image(mlx, texture);
	
	mlx_image_to_window(mlx, img, 0, 0);
	
	mlx_loop(mlx);
	mlx_terminate(mlx);
	
	return (0);
}

// int main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	void	*img;
// 	int		width; 
// 	int		height;
	
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 600, 600, "sprite");

// 	img = mlx_xpm_file_to_image(mlx, "sprite.xpm", &width, &height);
	
// 	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	
// 	mlx_loop(mlx);

// 	// mlx_destroy_image(mlx, img);
// 	// mlx_destroy_window(mlx, mlx_win);
// 	// free(mlx);
// }
