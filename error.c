/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 21:20:41 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/14 16:55:50 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "includes/lib_color/color.h"

int	error_miss_arg(void)
{
	ft_putstr_fd("usage : ./so-long [", 2);
	cyan();
	ft_putstr_fd("file", 2);
	reset();
	white();
	ft_putchar_fd('.', 2);
	reset();
	red();
	ft_putstr_fd("ber", 2);
	reset();
	ft_putstr_fd("]\n", 2);
	return (EXIT_FAILURE);
}

int	error_msg(char *s)
{
	red();
	ft_putstr_fd(s, 2);
	reset();
	return (FALSE);
}
