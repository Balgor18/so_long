/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:49:32 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/29 18:21:43 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

void	verif_width_and_height(t_all *all, t_mlx *mlx)
{
	(void)all;
	mlx_get_screen_size(mlx->mlx, &mlx->width, &mlx->height);
}
