/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:30:16 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/07 19:35:55 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

int	image_in_struct(t_all *all, t_img *i, char *file, void *mlx)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_trash(all);
		return (error_file(file));
	}
	close(fd);
	i->img = mlx_xpm_file_to_image(mlx, file, &i->width, &i->height);
	i->addr = (int *)mlx_get_data_addr(i->img, &i->bits_per_pixel,
			&i->line_length, &i->endian);
	return (SUCCES);
}

#if MAC_OS

void	image_in_window(t_mlx *mlx, char c, int line, int j)
{
	if (c == '0' || c == 'E' || c == 'C' || c == 'P' || c == 'A')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->ground.img, j * 64, line * 64);
	if (c == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->wall.img, j * 64, line * 64);
	if (c == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->exit.img, j * 64, line * 64);
	if (c == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->player.img, j * 64, (line - 1) * 64);
	if (c == 'A')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->ennemy.enn0.img, j * 64, line * 64);
}

void	put_texture_in_window(t_all *all)
{
	size_t	j;
	size_t	line;
	int		collec_width;
	int		collec_height;

	j = 0;
	line = 0;
	collec_height = (all->mlx.ground.height - all->mlx.collectible.height) / 2;
	collec_width = (all->mlx.ground.width - all->mlx.collectible.width) / 2;
	while (all->map.len > line)
	{
		j = 0;
		while (j < ft_strlen(all->map.map[line]))
		{
			image_in_window(&all->mlx, all->map.map[line][j], line, j);
			if (all->map.map[line][j] == 'C')
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.mlx_win,
					all->mlx.collectible.img, (j * 64) + collec_width,
					(line * 64) + collec_height);
			j++;
		}
		line++;
	}
}
#elif LINUX

void	pixel_to_image(t_img *win, t_img *i, int *win_pixel, int picture_pixel)
{
	int	pixel;

	pixel = 0;
	while (pixel < picture_pixel && *win_pixel < (win->width * win->height))
	{
		if (i->addr[pixel] != -16777216)
			win->addr[*win_pixel] = i->addr[pixel];
		*win_pixel += 1;
		pixel++;
	}
}

void	image_in_window(t_mlx *mlx, char c)
{
	static int	win_pixel = 0;

	//printf("win_pixel = %d\n", win_pixel);
	if (c == '0' || c == 'E' || c == 'C' || c == 'P')
		pixel_to_image(&mlx->window, &mlx->ground, &win_pixel,
			mlx->ground.width * mlx->ground.height);
	if (c == '1')
		pixel_to_image(&mlx->window, &mlx->wall, &win_pixel,
			mlx->wall.width * mlx->wall.height);
	if (c == 'E')
		pixel_to_image(&mlx->window, &mlx->exit, &win_pixel,
			mlx->exit.width * mlx->exit.height);
	if (c == 'P')
		pixel_to_image(&mlx->window, &mlx->player, &win_pixel,
			mlx->player.width * mlx->player.height);
	if (c == 'C')
		pixel_to_image(&mlx->window, &mlx->collectible, &win_pixel,
			mlx->collectible.width * mlx->collectible.height);
	//printf("win_pixel = %d\n---\n", win_pixel);
}

void	put_texture_in_window(t_all *all)
{
	size_t	j;
	size_t	line;

	j = 0;
	line = 0;
	printf("win_size addr = %d\n", all->mlx.window.width * all->mlx.window.height);
	while (all->map.len > line)
	{
		j = 0;
		while (j < ft_strlen(all->map.map[line]))
		{
			image_in_window(&all->mlx, all->map.map[line][j]);
			j++;
		}
		line++;
	}
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.mlx_win,
			all->mlx.window.img, 0, 0);
}
#endif
// pour le feu le faire bouger de haut en bas.
// faire 4 images
int	image_to_struct(t_mlx *mlx, t_all *all)
{
	if (!image_in_struct(all, &mlx->player, "texture/player.xpm", mlx->mlx))
		return (FAILURE);
	if (!image_in_struct(all, &mlx->ground, "texture/ground.xpm", mlx->mlx))
		return (FAILURE);
	if (!image_in_struct(all, &mlx->wall, "texture/wall.xpm", mlx->mlx))
		return (FAILURE);
	if (!image_in_struct(all, &mlx->exit, "texture/exit.xpm", mlx->mlx))
		return (FAILURE);
	if (!image_in_struct(all, &mlx->collectible, "texture/collectible.xpm",
			mlx->mlx))
		return (FAILURE);
	//if (!ennemy_in_struct(all))
	//	return (FAILURE);
	verif_width_and_height(all, mlx);
	mlx->window.img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	mlx->window.addr = (int *)mlx_get_data_addr(mlx->window.img,
			&mlx->window.bits_per_pixel, &mlx->window.line_length,
			&mlx->window.endian);
	mlx->window.width = mlx->width;
	mlx->window.height = mlx->height;
	return (SUCCES);
}
