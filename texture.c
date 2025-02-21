/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:49:32 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/15 14:53:55 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

#if MAC_OS

int	verif_width_and_height(t_all *all, t_mlx *mlx)
{
	int	width;
	int	maxwidth;
	int	height;
	int	maxheight;

	maxwidth = WIDTH / mlx->wall.width;
	maxheight = HEIGHT / mlx->wall.height;
	width = ft_strlen(all->map.map[0]);
	height = all->map.len;
	if (width >= maxwidth || height >= maxheight)
		return (error_msg("Not enough space for window\n"));
	mlx->width = width * mlx->wall.width;
	mlx->height = height * mlx->wall.height;
	return (TRUE);
}
#elif LINUX

int	verif_width_and_height(t_all *all, t_mlx *mlx)
{
	int	width;
	int	maxwidth;
	int	height;
	int	maxheight;

	mlx_get_screen_size(mlx->mlx, &mlx->width, &mlx->height);
	maxwidth = mlx->width / mlx->wall.width;
	maxheight = mlx->height / mlx->wall.height;
	width = ft_strlen(all->map.map[0]);
	height = all->map.len;
	if (width > maxwidth || height > maxheight)
		return (error_msg("Not enough space for window\n"));
	mlx->width = width * mlx->wall.width;
	mlx->height = height * mlx->wall.height;
	return (TRUE);
}
#endif
