/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:56:01 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/28 12:23:30 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

#include <stdio.h>
int	main(int agc, char **argv)
{
	t_all	all;

	if (agc < 2 || agc > 2)
		return (error_miss_arg());
	if (!verif_file_name(argv[1]))
		return (EXIT_FAILURE);
	init_struct(&all);
	parse_map(argv[1], &all);
	start_mlx(&all.mlx, &all);
	return (EXIT_SUCCESS);
}
