/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:30:16 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/08 11:27:53 by fcatinau         ###   ########.fr       */
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

/*#if MAC_OS

void	image_in_window(t_mlx *mlx, char c, int line, int j)
{
	if (c == '0' || c == 'E' || c == 'C' || c == 'P')
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
#elif LINUX*/
#include <stdio.h>
void	pixel_to_image(t_img *win, t_img *i, int win_pixel, int picture_pixel, char c)
{
	int	pixel;
	int	pibis;

	pibis = 0;
	pixel = 0;
	printf("char %c\nwin_pixel avant boucle %d\npicture_pixel = %d\n", c, win_pixel, picture_pixel);
	while (pixel <= picture_pixel && win_pixel <= (win->width * win->height))
	{
		if ((unsigned int)i->addr[pixel] != ALPHA)
			win->addr[win_pixel] = i->addr[pixel];
		win_pixel++;
		pixel++;
		if (pibis == 64)
		{
			win_pixel += win->width - 64;
			pibis = 0;
		}
		pibis++;
	}
}

// la texture standar et de 64 64
// mais la bombe fais du 48 48
// donc refaire les calculs de texture pour la bombe
void	bomb_pixel_to_image(t_img *win, t_img *i, int win_pixel, int picture_pixel)
{
	int	pixel;
	int	pibis;

	pibis = 0;
	pixel = 0;
	printf("win_pixel avant boucle %d\npicture_pixel = %d\n", win_pixel, picture_pixel);
	while (pixel <= picture_pixel && win_pixel <= (win->width * win->height))
	{
		if ((unsigned int)i->addr[pixel] != ALPHA)
			win->addr[win_pixel] = i->addr[pixel];
		win_pixel++;
		pixel++;
		if (pibis == 64)
		{
			win_pixel += win->width - 64;
			pibis = 0;
		}
		pibis++;
	}
}

void	image_in_window(t_mlx *mlx, char c, int j, int line)
{
	int	win_pixel;

	if (!line)
		win_pixel = j * 64;
	else
	{
		if (j != 0)
			win_pixel = mlx->window.width * 64 ;
		win_pixel = (line * (mlx->window.width * 64)) + (j * 64);
	}
	printf("j = %d\nline = %d\n", j, line);
	printf("-----\n%d\n", win_pixel);
	if (c == '0' || c == 'E' || c == 'C' || c == 'P')
		pixel_to_image(&mlx->window, &mlx->ground, win_pixel,
			mlx->ground.width * mlx->ground.height, 'G');
	if (c == '1')
		pixel_to_image(&mlx->window, &mlx->wall, win_pixel,
			mlx->wall.width * mlx->wall.height, 'W');
	if (c == 'E')
		pixel_to_image(&mlx->window, &mlx->exit, win_pixel,
			mlx->exit.width * mlx->exit.height, 'E');
	if (c == 'P')
		pixel_to_image(&mlx->window, &mlx->player,
			win_pixel - (mlx->window.width * 64),
			mlx->player.width * mlx->player.height, 'P');
	if (c == 'C')
		bomb_pixel_to_image(&mlx->window, &mlx->collectible, win_pixel,
			mlx->collectible.width * mlx->collectible.height);
	printf("----------\n");
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
//#endif

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
	verif_width_and_height(all, mlx);
	printf("texture bomb w = %d h = %d\n", mlx->collectible.width, mlx->collectible.height);
	printf("texture ground w = %d h = %d\n", mlx->ground.width, mlx->ground.height);
	mlx->window.img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	mlx->window.addr = (int *)mlx_get_data_addr(mlx->window.img,
			&mlx->window.bits_per_pixel, &mlx->window.line_length,
			&mlx->window.endian);
	mlx->window.width = mlx->width;
	mlx->window.height = mlx->height;
	return (SUCCES);
}
