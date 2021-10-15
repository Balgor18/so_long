/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_linux_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:30:16 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/13 17:00:40 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

void	pixel_to_image(t_img *win, t_img *i, int win_pixel, int picture_pixel)
{
	int	pixel;
	int	pibis;

	pibis = 0;
	pixel = 0;
	while (pixel < picture_pixel && win_pixel <= (win->width * win->height))
	{
		if ((unsigned int)i->addr[pixel] != ALPHA)
			win->addr[win_pixel] = i->addr[pixel];
		win_pixel += 1;
		pixel++;
		if (pibis == 64)
		{
			win_pixel += win->width - 64;
			pibis = 0;
		}
		pibis++;
	}
}

void	pixel_to_ground_image2(t_img *win, t_img *i, int pixel, int win_pixel)
{
	if ((unsigned int)i->addr[pixel] != ALPHA)
		win->addr[win_pixel + 1] = i->addr[pixel];
}

void	pixel_to_ground_image(t_img *win, t_img *i, int win_pxl, int pict_pxl)
{
	int	tmp;
	int	pixel;
	int	pibis;

	tmp = 0;
	pibis = 0;
	pixel = 0;
	while (pixel < pict_pxl && win_pxl <= (win->width * win->height))
	{
		if (!tmp)
			tmp = i->addr[pixel];
		else
			pixel_to_ground_image2(win, i, pixel, win_pxl);
		win_pxl += 1;
		pixel++;
		if (pibis == 64)
		{
			win_pxl += (win->width - 64);
			pibis = 0;
		}
		pibis++;
	}
	win->addr[win_pxl + 1] = tmp;
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
		win_pixel += 1;
		pixel++;
		if (pibis == 48)
		{
			win_pixel += win->width - 48 ;
			pibis = 0;
		}
		pibis++;
	}
}
