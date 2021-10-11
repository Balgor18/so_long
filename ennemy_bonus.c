/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:14:17 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/08 20:28:58 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"
#include <stdio.h>
int	ennemy_in_struct(t_all *all)
{
	if (!image_in_struct(all, &all->mlx.ennemy.enn0,
			"texture/ennemy/ennemy_00.xpm", all->mlx.mlx))
		return (FAILURE);
	if (!image_in_struct(all, &all->mlx.ennemy.enn1,
			"texture/ennemy/ennemy_01.xpm", all->mlx.mlx))
		return (FAILURE);
	if (!image_in_struct(all, &all->mlx.ennemy.enn2,
			"texture/ennemy/ennemy_02.xpm", all->mlx.mlx))
		return (FAILURE);
	if (!image_in_struct(all, &all->mlx.ennemy.enn3,
			"texture/ennemy/ennemy_03.xpm", all->mlx.mlx))
		return (FAILURE);
	if (!image_in_struct(all, &all->mlx.ennemy.enn4,
			"texture/ennemy/ennemy_04.xpm", all->mlx.mlx))
		return (FAILURE);
	return (SUCCES);
}
