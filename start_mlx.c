/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:28:10 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/30 18:37:22 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

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
	else if (key == D || key == RIGHT)
	{
		press_move(all, 'R');
	}
	else if (key == A || key == Q || key == LEFT)
	{
		press_move(all, 'L');
	}
	else if (key == S || key == DOWN)
	{
		press_move(all, 'D');
	}
	else if (key == W || key == Z || key == UP)
	{
		press_move(all, 'U');
	}
	return (0);
}

void	modify_picture_size(t_img *i, int width, int height)
{
	i->width = width;
	i->height = height;
}

void	calcul_picture_size(t_all *all)
{
	int	width_picture;
	int	height_picture;

	width_picture = 20;
	height_picture = 20;
	modify_picture_size(&all->mlx.player, width_picture, height_picture);
	modify_picture_size(&all->mlx.ground, width_picture, height_picture);
	modify_picture_size(&all->mlx.wall, width_picture, height_picture);
	modify_picture_size(&all->mlx.exit, width_picture, height_picture);
	modify_picture_size(&all->mlx.collectible, width_picture, height_picture);
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
	mlx_key_hook(mlx->mlx_win, key_hook, all);
	if (mlx->width == WIDTH || mlx->height == HEIGHT)
		calcul_picture_size(all);
	put_texture_in_map(all);
	mlx_loop(mlx->mlx);
}
