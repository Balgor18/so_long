/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:49:32 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/24 14:53:29 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verif_width_and_height(t_mlx *mlx)
{
	mlx_get_screen_size(mlx->mlx, &mlx->width, &mlx->height);
}
