/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:47:34 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/01 11:56:39 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

void	print_move(int nb)
{
	ft_putstr_fd("You did ", STDOUT);
	ft_putnbr_fd(nb, STDOUT);
	if (nb == 1)
		ft_putstr_fd(" move\r", STDOUT);
	else
		ft_putstr_fd(" moves\r", STDOUT);
}
