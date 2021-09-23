/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:49:32 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/23 17:38:22 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verif_width_and_height(t_mlx *mlx)
{
	if (WIDTH == 0 && HEIGHT == 0)
		mlx_get_screen_size(mlx->mlx, &mlx->width, &mlx->height);
	else
	{
		mlx->width = WIDTH;
		mlx->height = HEIGHT;
	}
}
