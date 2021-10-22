/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:33:16 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/22 08:28:13 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

void	end_exit(t_all *all)
{
	mlx_do_key_autorepeaton(all->mlx.mlx);
	ft_trash(all);
	exit(0);
}
