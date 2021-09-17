/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:52:41 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/17 20:02:31 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_all *all)
{
	(void)all;
	//Do nothing
}

void	init_char_map(t_char_map *cm)
{
	cm->count_c = 0;
	cm->count_e = 0;
	cm->count_p = 0;
}
