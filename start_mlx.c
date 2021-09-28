/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:28:10 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/28 12:23:05 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

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
#include <stdio.h>
int	key_hook(int key, t_all *all)
{
	printf("key = %d\n", key);
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

void	print_image_size(t_img *i, char *s)
{
	printf("----------\n%s\nwidth = %d\nheight=%d\n----------\n", s, i->width, i->height);
}

void	modify_picture_size(t_img *i, int width, int height)
{
	i->width = width;
	i->height = height;
}

void	calcul_picture_size(t_all *all)
{
	int	len;
	int	width_picture;
	int height_picture;

	len = ft_strlen(all->map.map[0]);
	width_picture = WIDTH / len;
	height_picture = HEIGHT / all->map.len;
	modify_picture_size(&all->mlx.player, width_picture, height_picture);
	modify_picture_size(&all->mlx.ground, width_picture, height_picture);
	modify_picture_size(&all->mlx.wall, width_picture, height_picture);
	modify_picture_size(&all->mlx.exit, width_picture, height_picture);
	modify_picture_size(&all->mlx.collectible, width_picture, height_picture);
}

void	start_mlx(t_mlx *mlx, t_all *all)
{
	// bonus use mlx_string_put

	mlx->mlx = mlx_init();
	verif_width_and_height(mlx);
	mlx->mlx_win = mlx_new_window(mlx->mlx, 100, 100, "so_long");
	//mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "so_long");
	image_in_struct(&mlx->player, "texture/player.xpm", mlx->mlx);
	image_in_struct(&mlx->ground, "texture/ground.xpm", mlx->mlx);
	image_in_struct(&mlx->wall, "texture/wall.xpm", mlx->mlx);
	image_in_struct(&mlx->exit, "texture/exit.xpm", mlx->mlx);
	image_in_struct(&mlx->collectible, "texture/collectible.xpm", mlx->mlx);

	mlx_key_hook(mlx->mlx_win, key_hook, all);
	calcul_picture_size(all);
	//mlx->player.height = 64;
	print_image_size(&mlx->player, "Player");
	print_image_size(&mlx->ground, "Ground");

	print_image_size(&mlx->wall, "Wall");
	print_image_size(&mlx->exit, "Exit");
	print_image_size(&mlx->collectible, "Collectible");
	//exit(124);
	//mlx_mouse_hook(mlx->mlx_win, mouse_hook, all);
	//exit(125);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->ground.img, 0, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->player.img, 0, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->wall.img, 100, 300);
	//put_texture_in_map();
	mlx_loop(mlx->mlx);
	// in case of refresh map
	// mlx_clear_window
	// putimage
	// and mlx_loop
}
