/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:28:10 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/21 17:33:26 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
*/
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int key, t_all *all)
{
	if (key == ESCAPE)
	{
		mlx_clear_window(all->mlx.mlx, all->mlx.mlx_win);
		ft_trash(all);
		exit(0);
	}
	return (0);
}

#include <stdio.h>
/*
int	mouse_hook(int mouse, t_all *all)
{
	(void)all;
	printf("%d\n", mouse);
	return (0);
}*/

void	start_mlx(t_mlx *mlx, t_all *all)
{
	// bonus use mlx_string_put
	char	*file = "texture/player.png";

	//mlx->img.width = 1920;
	//mlx->img.height = 1080;

	//mlx->img.width = 1920;
	//mlx->img.height = 1080;
	// Hypothese

	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, 1920, 1080, "so_long");
	//mlx->img.img = mlx_xpm_file_to_image(mlx->mlx, "platypus.xpm", &mlx->img.width, &mlx->img.height);

	//mlx->img.img = mlx_png_file_to_image(mlx->mlx, "texture/player.png", &mlx->img.width, &mlx->img.height);

	mlx->img.width = 4;
	mlx->img.height = 4;
	mlx->img.img = mlx_xpm_file_to_image(mlx->mlx, file, &mlx->img.width, &mlx->img.height);

	//mlx->img.img = mlx_xpm_to_image(mlx->mlx, &file, &mlx->img.width, &mlx->img.height);

	//mlx->img.img = mlx_png_to_image(mlx->mlx, "texture/player.png", &mlx->img.width, &mlx->img.height);

	//mlx->img.img = mlx_xpm_file_to_image(mlx->mlx, file, &mlx->img.width, &mlx->img.height);
	//mlx_new_image()
	//mlx->img.img = mlx_new_image(mlx->mlx, mlx->img.width, mlx->img.height);
	/*mlx->img.addr = mlx_get_data_addr(mlx->img.img,
			&mlx->img.bits_per_pixel, &mlx->img.line_length,
			&mlx->img.endian);*/
	mlx_key_hook(mlx->mlx_win, key_hook, all);
	//my_mlx_pixel_put(&mlx->img, 5, 5, 0x00FF0000);// print pixel
	//mlx_mouse_hook(mlx->mlx_win, mouse_hook, all);
	printf("%d, %d \n", mlx->img.width, mlx->img.height);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.img, 0, 0);
	//mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.img, 100, 300);
	mlx_loop(mlx->mlx);
}
