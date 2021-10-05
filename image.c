/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:30:16 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/05 11:41:32 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"
#include <stdio.h>
int	image_in_struct(t_img *i, char *file, void *mlx)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (error_file(file));
	}
	close(fd);
	i->img = mlx_xpm_file_to_image(mlx, file, &i->width, &i->height);
	i->addr = mlx_get_data_addr(i->img, &i->bits_per_pixel,
			&i->line_length, &i->endian);
	printf("%s i->addr = |%d|%d|%d|%d|\n", file, i->addr[0], i->addr[1], i->addr[2], i->addr[3]);
	if (i->addr[3] == -1)
		i->addr[3] = (unsigned char)50;
	printf("%s i->addr = |%d|%d|%d|%d|\n------\n", file, i->addr[0], i->addr[1], i->addr[2], i->addr[3]);
	return (SUCCES);
}

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

void	put_texture_in_map(t_all *all)
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
