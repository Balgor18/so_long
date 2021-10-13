/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_linux_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:30:16 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/13 08:58:28 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"
#include <stdio.h>
void	pixel_to_image(t_img *win, t_img *i, int win_pixel, int picture_pixel)
{
	int	pixel;
	int	pibis;

	pibis = 0;
	pixel = 0;
	win_pixel--;
	while (pixel <= picture_pixel && win_pixel <= (win->width * win->height))
	{
		if ((unsigned int)i->addr[pixel] != ALPHA)
			win->addr[win_pixel] = i->addr[pixel];
		win_pixel++;
		pixel++;
		if (pibis == 64)
		{
			win_pixel += win->width - 64;
			pibis = 0;
		}
		pibis++;
	}
}

void	bomb_pixel_to_image(t_img *win, t_img *i, int win_pixel, int p_pixel)
{
	int	pixel;
	int	pibis;

	pibis = 0;
	pixel = 0;
	win_pixel += win->width * 8;
	win_pixel += 8;
	while (pixel < p_pixel && win_pixel <= (win->width * win->height))
	{
		if ((unsigned int)i->addr[pixel] != ALPHA)
			win->addr[win_pixel] = i->addr[pixel];
		win_pixel++;
		pixel++;
		if (pibis == 48)
		{
			win_pixel += win->width - 48 ;
			pibis = 0;
		}
		pibis++;
	}
}
