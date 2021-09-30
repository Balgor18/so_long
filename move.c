/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:01:34 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/30 18:37:17 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

void	move_up(t_map *map)
{
	(void)map;
}

void	move_down(t_map *map)
{
	(void)map;
}

void	move_left(t_map *map)
{
	(void)map;
}

void	move_right(t_map *map)
{
	(void)map;
}

void	press_move(t_map *map, char move)
{
	int	move;

	move = 0
	if (move == 'U')
		move_up(map);
	else if (move == 'D')
		move_down(map);
	else if (move == 'L')
		move_left(map);
	else if (move == 'R')
		move_right(map);
	if (move == 0)
		printf("You did %d move\r", ++move);
	else
		printf("You did %d moves\r", ++move);
}
