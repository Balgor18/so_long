/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:52:41 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/28 12:23:30 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

void	init_img(t_img *i)
{
	i->addr = NULL;
	i->img = NULL;
}


void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_win = NULL;
	mlx->mlx = NULL;
	init_img(&mlx->exit);
	init_img(&mlx->player);
	init_img(&mlx->wall);
	init_img(&mlx->collectible);
}

void	init_struct(t_all *all)
{
	(void)all;
	//Do nothing
	init_mlx(&all->mlx);
}

void	init_char_map(t_char_map *cm)
{
	cm->count_c = 0;
	cm->count_e = 0;
	cm->count_p = 0;
}
