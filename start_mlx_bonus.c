/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:28:10 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/22 08:28:37 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

int	key_hook(int key, t_all *all)
{
	if (key == ESCAPE)
	{
		mlx_clear_window(all->mlx.mlx, all->mlx.mlx_win);
		ft_trash(all);
		exit(0);
	}
	else if (key == D || key == RIGHT)
		press_move(all, &all->map, 'R');
	else if (key == A || key == Q || key == LEFT)
		press_move(all, &all->map, 'L');
	else if (key == S || key == DOWN)
		press_move(all, &all->map, 'D');
	else if (key == W || key == Z || key == UP)
		press_move(all, &all->map, 'U');
	return (0);
}

void	reset_image_put_to_window(t_all *all)
{
	mlx_do_key_autorepeaton(all->mlx.mlx);
	mlx_clear_window(all->mlx.mlx, all->mlx.mlx_win);
	put_texture_in_window(all);
	print_move(all);
	mlx_loop(all->mlx.mlx);
}

int	ft_close(t_all *all)
{
	mlx_do_key_autorepeaton(all->mlx.mlx);
	ft_trash(all);
	exit(0);
	return (0);
}

int	start_mlx(t_mlx *mlx, t_all *all)
{
	mlx->mlx = mlx_init();
	if (!image_to_struct(mlx, all))
		return (FAILURE);
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "so_long");
	mlx_do_key_autorepeatoff(mlx->mlx);
	mlx_hook(mlx->mlx_win, 2, 1L << 0, key_hook, all);
	mlx_hook(mlx->mlx_win, 33, 1L << 17, ft_close, all);
	put_texture_in_window(all);
	print_move(all);
	mlx_loop(mlx->mlx);
	return (SUCCES);
}
