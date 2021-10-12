/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:01:34 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/12 11:11:29 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

void	move_up(t_all *all, t_map *map, int *move)
{
	if (map->map[map->player.y - 1][map->player.x] == '1')
		return ;
	if (map->map[map->player.y - 1][map->player.x] == 'E')
	{
		if (map->goal == map->collect)
			end_exit(all);
		return ;
	}
	*move += 1;
	if (map->map[map->player.y - 1][map->player.x] == 'C')
	{
		map->collect++;
		map->map[map->player.y][map->player.x] = '0';
	}
	if (map->map[map->player.y - 1][map->player.x] != 'E')
	{
		map->map[map->player.y][map->player.x] = '0';
		map->player.y = map->player.y - 1;
		map->map[map->player.y][map->player.x] = 'P';
	}
	return ;
}

void	move_down(t_all *all, t_map *map, int *move)
{
	if (map->map[map->player.y + 1][map->player.x] == '1')
		return ;
	if (map->map[map->player.y + 1][map->player.x] == 'E')
	{
		if (map->goal == map->collect)
			end_exit(all);
		return ;
	}
	*move += 1;
	if (map->map[map->player.y + 1][map->player.x] == 'C')
	{
		map->collect++;
		map->map[map->player.y][map->player.x] = '0';
	}
	if (map->map[map->player.y + 1][map->player.x] != 'E')
	{
		map->map[map->player.y][map->player.x] = '0';
		map->player.y = map->player.y + 1;
		map->map[map->player.y][map->player.x] = 'P';
	}
	return ;
}

void	move_left(t_all *all, t_map *map, int *move)
{
	if (map->map[map->player.y][map->player.x - 1] == '1')
		return ;
	if (map->map[map->player.y][map->player.x - 1] == 'E')
	{
		if (map->goal == map->collect)
			end_exit(all);
		return ;
	}
	*move += 1;
	if (map->map[map->player.y][map->player.x - 1] == 'C')
	{
		map->collect++;
		map->map[map->player.y][map->player.x] = '0';
	}
	if (map->map[map->player.y][map->player.x - 1] != 'E')
	{
		map->map[map->player.y][map->player.x] = '0';
		map->player.x = map->player.x - 1;
		map->map[map->player.y][map->player.x] = 'P';
	}
	return ;
}

void	move_right(t_all *all, t_map *map, int *move)
{
	if (map->map[map->player.y][map->player.x + 1] == '1')
		return ;
	if (map->map[map->player.y][map->player.x + 1] == 'E')
	{
		if (map->goal == map->collect)
			end_exit(all);
		return ;
	}
	*move += 1;
	if (map->map[map->player.y][map->player.x + 1] == 'C')
	{
		map->collect++;
		map->map[map->player.y][map->player.x] = '0';
	}
	if (map->map[map->player.y][map->player.x + 1] != 'E')
	{
		map->map[map->player.y][map->player.x] = '0';
		map->player.x = map->player.x + 1;
		map->map[map->player.y][map->player.x] = 'P';
	}
	return ;
}

void	press_move(t_all *all, t_map *map, char m)
{
	if (m == 'U')
		move_up(all, map, &map->player.move);
	else if (m == 'D')
		move_down(all, map, &map->player.move);
	else if (m == 'L')
		move_left(all, map, &map->player.move);
	else if (m == 'R')
		move_right(all, map, &map->player.move);
	if (m != 'E')
		reset_image_put_to_window(all);
}
