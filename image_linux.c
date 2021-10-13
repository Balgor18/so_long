/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_linux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:30:16 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/13 17:02:05 by fcatinau         ###   ########.fr       */
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

int	calcul_win_pixel(t_mlx *mlx, int line, int j)
{
	int	win_pixel;

	if (!line)
		win_pixel = j * 64;
	else
	{
		if (j != 0)
			win_pixel = mlx->window.width * 64;
		win_pixel = (line * (mlx->window.width * 64)) + (j * 64);
	}
	return (win_pixel);
}

void	image_in_window(t_mlx *mlx, char c, int j, int line)
{
	int	win_pixel;

	win_pixel = calcul_win_pixel(mlx, line, j);
	if (c == '0' || c == 'E' || c == 'C' || c == 'P')
		pixel_to_image(&mlx->window, &mlx->ground, win_pixel - 1,
			(mlx->ground.width * mlx->ground.height));
	if (c == '1')
		pixel_to_image(&mlx->window, &mlx->wall, win_pixel,
			mlx->wall.width * mlx->wall.height);
	if (c == 'E')
		pixel_to_image(&mlx->window, &mlx->exit, win_pixel,
			mlx->exit.width * mlx->exit.height);
	if (c == 'P')
		pixel_to_image(&mlx->window, &mlx->player,
			win_pixel - (mlx->window.width * 64),
			mlx->player.width * mlx->player.height);
	if (c == 'C')
		bomb_pixel_to_image(&mlx->window, &mlx->collectible, win_pixel,
			mlx->collectible.width * mlx->collectible.height);
}

void	put_texture_in_window(t_all *all)
{
	size_t	j;
	size_t	line;

	j = 0;
	line = 0;
	while (all->map.len > line)
	{
		j = 0;
		while (j < ft_strlen(all->map.map[line]))
		{
			image_in_window(&all->mlx, all->map.map[line][j], j, line);
			j++;
		}
		line++;
	}
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.mlx_win,
		all->mlx.window.img, 0, 0);
}

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
	if (!verif_width_and_height(all, mlx))
	{
		free_map(&all->map);
		free_mlx(&all->mlx);
		return (FAILURE);
	}
	mlx->window.img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	mlx->window.addr = (int *)mlx_get_data_addr(mlx->window.img,
			&mlx->window.bits_per_pixel, &mlx->window.line_length,
			&mlx->window.endian);
	mlx->window.width = mlx->width;
	mlx->window.height = mlx->height;
	return (SUCCES);
}
