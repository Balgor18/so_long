/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:46:49 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/13 11:47:35 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void	test(void)
{
	black();
	ft_putstr_fd("Black \n", 1);
	reset();
	blue();
	ft_putstr_fd("Blue \n", 1);
	reset();
	cyan();
	ft_putstr_fd("Cyan \n", 1);
	reset();
	green();
	ft_putstr_fd("Green \n", 1);
	reset();
	purple();
	ft_putstr_fd("Purple \n", 1);
	reset();
	red();
	ft_putstr_fd("Red \n", 1);
	reset();
	white();
	ft_putstr_fd("White \n", 1);
	reset();
	yellow();
	ft_putstr_fd("Yellow \n", 1);
	reset();
}
