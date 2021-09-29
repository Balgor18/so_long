/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:49:32 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/29 18:32:39 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"
#include <stdio.h>
void	verif_width_and_height(t_all *all, t_mlx *mlx)
{
	int	width;
	int	maxwidth;
	int	height;
	int	maxheight;

	maxheight = HEIGHT / all->map.len;
	maxwidth = WIDTH / ft_strlen(all->map.map[0]);
	width = mlx->wall.width / ft_strlen(all->map.map[0]);
	height = mlx->wall.height / all->map.len;
	if (width < maxwidth)
		mlx->width = width * mlx->wall.width;
	if (height < maxheight)
		mlx->height = height * mlx->wall.height;
	/*if (WIDTH != 0 && HEIGHT != 0)
	{
		mlx->width = WIDTH;
		mlx->height = HEIGHT;
	}*/
}
