/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:34:41 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/08 20:15:59 by fcatinau         ###   ########.fr       */
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

void	free_ennemy(t_mlx *mlx, t_ennemy *enn)
{
	if (enn->enn0.img)
		mlx_destroy_image(mlx->mlx, enn->enn0.img);
	if (enn->enn1.img)
		mlx_destroy_image(mlx->mlx, enn->enn1.img);
	if (enn->enn2.img)
		mlx_destroy_image(mlx->mlx, enn->enn2.img);
	if (enn->enn3.img)
		mlx_destroy_image(mlx->mlx, enn->enn3.img);
	if (enn->enn4.img)
		mlx_destroy_image(mlx->mlx, enn->enn4.img);
}

#if LINUX

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
	if (mlx->window.img)
		mlx_destroy_image(mlx->mlx, mlx->window.img);
	if (mlx->mlx_win)
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	free_ennemy(mlx, &mlx->ennemy);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
}
#else

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
	if (mlx->window.img)
		mlx_destroy_image(mlx->mlx, mlx->window.img);
	if (mlx->mlx_win)
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	free_ennemy(mlx, &mlx->ennemy);
	if (mlx->mlx)
		free(mlx->mlx);
}
#endif

void	ft_trash(t_all *all)
{
	free_map(&all->map);
	free_mlx(&all->mlx);
}
