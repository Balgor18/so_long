/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 21:20:41 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/15 15:38:38 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "includes/lib_color/color.h"

int	error_miss_arg(void)
{
	ft_putstr_fd("usage : ./so_long [", STRERR);
	cyan();
	ft_putstr_fd("file", STRERR);
	reset();
	white();
	ft_putchar_fd('.', STRERR);
	reset();
	red();
	ft_putstr_fd("ber", STRERR);
	reset();
	ft_putstr_fd("]\n", STRERR);
	return (EXIT_FAILURE);
}

int	error_msg(char *s)
{
	red();
	ft_putstr_fd(s, STRERR);
	reset();
	return (FALSE);
}
