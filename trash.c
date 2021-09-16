/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:34:41 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/16 12:51:45 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
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
	//if (mlx->mlx_img)
	//	mlx_destroy_image(mlx->mlx, mlx->mlx_img);
	/*if (mlx->mlx_win)
	{
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	}*/
	if (mlx->mlx)
		free(mlx->mlx);
}

void	ft_trash(t_all *all)
{
	free_map(&all->map);
	free_mlx(&all->mlx);
}
