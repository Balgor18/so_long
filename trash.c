/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:34:41 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/04 17:56:27 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->len)
		free(map->map[i++]);
	free(map->map);
}

void	free_mlx(t_mlx	*mlx)
{
	if (mlx->player.img)
		mlx_destroy_image(mlx->mlx, mlx->player.img);
	if (mlx->wall.img)
		mlx_destroy_image(mlx->mlx, mlx->wall.img);
	if (mlx->ground.img)
		mlx_destroy_image(mlx->mlx, mlx->ground.img);
	if (mlx->exit.img)
		mlx_destroy_image(mlx->mlx, mlx->exit.img);
	if (mlx->collectible.img)
		mlx_destroy_image(mlx->mlx, mlx->collectible.img);
	if (mlx->mlx_win)
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
}

void	ft_trash(t_all *all)
{
	free_map(&all->map);
	free_mlx(&all->mlx);
}
