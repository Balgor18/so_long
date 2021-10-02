/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:28:10 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/01 18:00:21 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

int	key_hook(int key, t_all *all)
{
	if (key == ESCAPE)
	{
		mlx_clear_window(all->mlx.mlx, all->mlx.mlx_win);
		ft_trash(all);
		exit(0);
	}
	else if (key == D || key == RIGHT)
		press_move(all, &all->map, 'R');
	else if (key == A || key == Q || key == LEFT)
		press_move(all, &all->map, 'L');
	else if (key == S || key == DOWN)
		press_move(all, &all->map, 'D');
	else if (key == W || key == Z || key == UP)
		press_move(all, &all->map, 'U');
	return (0);
}

void	reset_image_put_to_window(t_all *all)
{
	mlx_clear_window(all->mlx.mlx, all->mlx.mlx_win);
	mlx_key_hook(all->mlx.mlx_win, key_hook, all);
	if (all->mlx.width == WIDTH || all->mlx.height == HEIGHT)
		calcul_picture_size(all);
	put_texture_in_map(all);
	mlx_loop(all->mlx.mlx);
}
#include <stdio.h>
int	mouse_hook(int mouse, t_all *all)
{
	(void)all;
	printf("mouse = %d\n", mouse);
	return (0);
}

	// bonus use mlx_string_put
void	start_mlx(t_mlx *mlx, t_all *all)
{
	mlx->mlx = mlx_init();
	image_in_struct(&mlx->player, "texture/player.xpm", mlx->mlx);
	image_in_struct(&mlx->ground, "texture/ground.xpm", mlx->mlx);
	image_in_struct(&mlx->wall, "texture/wall.xpm", mlx->mlx);
	image_in_struct(&mlx->exit, "texture/exit.xpm", mlx->mlx);
	image_in_struct(&mlx->collectible, "texture/collectible.xpm", mlx->mlx);
	verif_width_and_height(all, mlx);
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "so_long");
	mlx_hook(mlx->mlx_win, 4, 1L << 0, key_hook, all);
	mlx_hook(mlx->mlx_win, 8, 1L << 5, mouse_hook, all);
	//mlx_key_hook(mlx->mlx_win, key_hook, all);
	//mlx_mouse_hook(mlx->mlx_win, mouse_hook, all);
	if (mlx->width == WIDTH || mlx->height == HEIGHT)
		calcul_picture_size(all);
	put_texture_in_map(all);
	mlx_loop(mlx->mlx);
}
