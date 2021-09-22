/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:49:32 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/22 16:52:34 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_in_struct(t_img *i, char *file, void *mlx)
{
	i->img = mlx_xpm_file_to_image(mlx, file, &i->width, &i->height);
	i->addr = mlx_get_data_addr(i->img, &i->bits_per_pixel,
			&i->line_length, &i->endian);
}
/*
void	image_in_window(t_mlx *mlx, int line, int pos)
{

}

void	put_texture_in_map(t_all *all)
{
	int	line;
	int	j;

	line = 0;
	j = 0;
	while (all->map.len > line)
	{
		while (all->map.map[line][j])
		{
			image_in_window();
			j++;
		}
		line++;
	}
}*/
