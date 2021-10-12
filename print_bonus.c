/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:47:34 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/12 11:12:37 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

int	ft_int_len(int nb)
{
	int	len;

	len = 2;
	while (nb > 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

void	print_move(t_all *all)
{
	char	*nb_str;
	int		len;

	nb_str = ft_itoa(all->map.player.move);
	len = ft_int_len(all->map.player.move);
	len = (len * 2) + 80;
	if (all->map.player.move < 2)
		mlx_string_put(all->mlx.mlx, all->mlx.mlx_win, 30, 30, WHITE, "Move :");
	else
		mlx_string_put(all->mlx.mlx, all->mlx.mlx_win,
			30, 30, WHITE, "Moves :");
	mlx_string_put(all->mlx.mlx, all->mlx.mlx_win, len, 30, WHITE, nb_str);
	free(nb_str);
	return ;
}
