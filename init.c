/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:52:41 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/10 11:33:01 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

void	init_img(t_img *i)
{
	i->addr = NULL;
	i->img = NULL;
	i->width = 0;
	i->height = 0;
	i->bits_per_pixel = 0;
	i->line_length = 0;
	i->endian = 0;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->mlx_win = NULL;
	mlx->width = 0;
	mlx->height = 0;
	init_img(&mlx->player);
	init_img(&mlx->ground);
	init_img(&mlx->wall);
	init_img(&mlx->exit);
	init_img(&mlx->collectible);
	init_img(&mlx->window);
}

void	init_struct(t_all *all)
{
	all->map.map = NULL;
	all->map.len = 0;
	all->map.goal = 0;
	all->map.collect = 0;
	all->map.player.move = 0;
	all->map.player.x = 0;
	all->map.player.y = 0;
	init_mlx(&all->mlx);
}

void	init_char_map(t_char_map *cm)
{
	cm->count_c = 0;
	cm->count_e = 0;
	cm->count_p = 0;
}
