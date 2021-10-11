/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:38:58 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/10 17:51:42 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"
#include <stdio.h>
void	move_ennemy(t_map *map, int line, int x)
{
	if (map->map[line - 1][x] == '1')
	{
		map->map[line][x] = '0';
		map->map[line + 1][x] = 'A';
	}
	else if (map->map[line + 1][x] == '1')
	{
		map->map[line][x] = '0';
		map->map[line - 1][x] = 'A';
	}
}

void	check_ennemy(t_all *all)
{
	size_t	line;
	size_t	i;

	i = 0;
	line = 0;
	while (line < all->map.len)
	{
		while (i < ft_strlen(all->map.map[line]))
		{
			if (all->map.map[line][i] == 'A')
				move_ennemy(&all->map, line, i);
			i++;
		}
		line++;
	}
}


//change the refresh off the map
//use this fonction and modify the player movement with this(verif if posible)
// check for move the ennemy every 2 seconde and for that check if the programme dont take to much time for refresh the picture.
int	anim_fire(t_all *all)
{
//	while (TRUE)
//	{
	sleep(5);
	printf("coucou\n");
	check_ennemy(all);
	mlx_clear_window(all->mlx.mlx, all->mlx.mlx_win);
	put_texture_in_window(all);
	print_move(all);
//	}
	return (TRUE);
}
