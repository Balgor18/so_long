/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:47:34 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/09 17:55:06 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

void	print_move(t_all *all)
{
	ft_putstr_fd("You did ", STDOUT);
	ft_putnbr_fd(all->map.player.move, STDOUT);
	if (all->map.player.move == 1)
		ft_putstr_fd(" move\r", STDOUT);
	else
		ft_putstr_fd(" moves\r", STDOUT);
}
