/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:49:32 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/23 17:43:58 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
void	verif_width_and_height(t_mlx *mlx)
{
	printf("avant width %d\nheight %d\n",mlx->width, mlx->height);
	if (WIDTH != 0 && HEIGHT != 0)
	{
		mlx->width = WIDTH;
		mlx->height = HEIGHT;
	}
	printf("apres width %d\nheight %d\n",mlx->width, mlx->height);
}
