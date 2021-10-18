/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:11:05 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/18 19:11:18 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

void	ft_gnl_trash(int fd)
{
	int		ret;
	char	*line;

	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		free(line);
		ret = get_next_line(fd, &line);
	}
	free(line);
}
