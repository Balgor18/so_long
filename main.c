/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:56:01 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/14 17:19:22 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int agc, char **argv)
{
	(void)argv;
	if (agc < 2)
		return (error_miss_arg());
	return (EXIT_SUCCESS);
}
