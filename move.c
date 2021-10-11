/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:01:34 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/09 17:54:27 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

void	move_up(t_all *all, t_map *map)
{
	if (map->map[map->player.y - 1][map->player.x] == '1')
		return ;
	if (map->map[map->player.y - 1][map->player.x] == 'E')
	{
		if (map->goal == map->collect)
			end_exit(all);
		return ;
	}
	map->player.move += 1;
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

void	move_down(t_all *all, t_map *map)
{
	if (map->map[map->player.y + 1][map->player.x] == '1')
		return ;
	if (map->map[map->player.y + 1][map->player.x] == 'E')
	{
		if (map->goal == map->collect)
			end_exit(all);
		return ;
	}
	map->player.move += 1;
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

void	move_left(t_all *all, t_map *map)
{
	if (map->map[map->player.y][map->player.x - 1] == '1')
		return ;
	if (map->map[map->player.y][map->player.x - 1] == 'E')
	{
		if (map->goal == map->collect)
			end_exit(all);
		return ;
	}
	map->player.move += 1;
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

void	move_right(t_all *all, t_map *map)
{
	if (map->map[map->player.y][map->player.x + 1] == '1')
		return ;
	if (map->map[map->player.y][map->player.x + 1] == 'E')
	{
		if (map->goal == map->collect)
			end_exit(all);
		return ;
	}
	map->player.move += 1;
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
		move_up(all, map);
	else if (m == 'D')
		move_down(all, map);
	else if (m == 'L')
		move_left(all, map);
	else if (m == 'R')
		move_right(all, map);
	if (m != 'E')
		reset_image_put_to_window(all);
}
