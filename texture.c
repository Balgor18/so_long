/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:49:32 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/30 11:48:07 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

void	verif_width_and_height(t_all *all, t_mlx *mlx)
{
	int		width;
	int		maxwidth;
	int		height;
	int		maxheight;

	maxwidth = WIDTH / mlx->wall.width;
	maxheight = HEIGHT / mlx->wall.height;
	width =ft_strlen(all->map.map[0]);
	height = all->map.len;
	if (width < maxwidth)
		mlx->width = width * mlx->wall.width;
	if (height < maxheight)
		mlx->height = height * mlx->wall.height;
}
