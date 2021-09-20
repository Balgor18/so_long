/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 21:20:41 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/20 15:44:25 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "includes/lib_color/color.h"

void	error_close(int fd, char *s)
{
	close(fd);
	error_msg(s);
	exit (EXIT_FAILURE);
}

int	error_char(int p, int e, int c)
{
	if (c == 0)
		error_msg("No collectible in map\n");
	else if (e == 0)
		error_msg("No exit in map\n");
	else if (p == 0)
		error_msg("No player position in map\n");
	else if (p > 1)
		error_msg("Too much player position in map\n");
	return (FALSE);
}

int	error_miss_arg(void)
{
	red();
	ft_putstr_fd("Error\n", 2);
	reset();
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
