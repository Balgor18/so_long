/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 21:20:41 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/17 13:51:04 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "includes/lib_color/color.h"

int	error_miss_arg(void)
{
	ft_putstr_fd("usage : ./so_long [", STDERR);
	cyan();
	ft_putstr_fd("file", STDERR);
	reset();
	white();
	ft_putchar_fd('.', STDERR);
	reset();
	red();
	ft_putstr_fd("ber", STDERR);
	reset();
	ft_putstr_fd("]\n", STDERR);
	return (EXIT_FAILURE);
}

// Error msg display the string s on STDERR
// AND return 0 for FALSE
int	error_msg(char *s)
{
	red();
	ft_putstr_fd("Error\n", 2);
	reset();
	white();
	ft_putstr_fd(s, STDERR);
	reset();
	return (FALSE);
}
