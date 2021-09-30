/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:30:16 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/30 13:15:35 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"
#include <stdio.h>
void	image_in_struct(t_img *i, char *file, void *mlx)
{
	i->img = mlx_xpm_file_to_image(mlx, file, &i->width, &i->height);
	i->addr = mlx_get_data_addr(i->img, &i->bits_per_pixel,
			&i->line_length, &i->endian);
}

void	image_in_window(t_mlx *mlx, t_img *i, int line, int pos)
{
	printf("On balance une image\n");
	printf("line = %d\npos = %d\n", line, pos);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, i->img, pos, line);
}

void	put_texture_in_map(t_all *all)
{
	size_t	line;
	size_t	j;

	line = 0;
	j = 0;
	while (all->map.len > line)
	{
		j = 0;
		while (j < ft_strlen(all->map.map[line]))
		{
			if (all->map.map[line][j] == '0')
				image_in_window(&all->mlx, &all->mlx.ground, line * 64, j * 64);
			else if (all->map.map[line][j] == '1')
				image_in_window(&all->mlx, &all->mlx.wall, line * 64, j * 64);
			else if (all->map.map[line][j] == 'E')
			{
				image_in_window(&all->mlx, &all->mlx.ground, line * 64, j * 64);
				image_in_window(&all->mlx, &all->mlx.exit, line * 64, j * 64);
			}
			else if (all->map.map[line][j] == 'C')
			{
				image_in_window(&all->mlx, &all->mlx.ground, line * 64, j * 64);
				image_in_window(&all->mlx, &all->mlx.collectible, line * 64, j * 64);
			}
			else if (all->map.map[line][j] == 'P')
			{
				image_in_window(&all->mlx, &all->mlx.ground, line * 64, j * 64);
				image_in_window(&all->mlx, &all->mlx.player, (line - 1)* 64, j * 64);
			}
			j++;
		}
		line++;
	}
}
