/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:47:34 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/07 15:11:34 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

void	print_move(t_all *all, int nb)
{
	(void)all;
	ft_putstr_fd("You did ", STDOUT);
	ft_putnbr_fd(nb, STDOUT);
	if (nb == 1)
		ft_putstr_fd(" move\r", STDOUT);
	else
		ft_putstr_fd(" moves\r", STDOUT);
}
