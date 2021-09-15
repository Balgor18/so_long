/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:28:10 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/15 18:44:25 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	key_hook(int key, t_all *all)
{
	if (key == 53)
	{
		mlx_clear_window(all->mlx.mlx, all->mlx.mlx_win);
		ft_trash(all);
		exit(0);
	}
	return (0);
}

void	start_mlx(t_mlx *mlx, t_all *all)
{
	(void)all;
	mlx->img.width = 1920;
	mlx->img.height = 1080;
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->img.width,
			mlx->img.height, "so_long");
	mlx->img.img = mlx_new_image(mlx->mlx, mlx->img.width, mlx->img.height);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img,
			&mlx->img.bits_per_pixel, &mlx->img.line_length,
			&mlx->img.endian);
	mlx_key_hook(mlx->mlx_win, key_hook, all);
	//try(&mlx->img, all);
	//mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.img, 0, 0);
	mlx_loop(mlx->mlx);
}
