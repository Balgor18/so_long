/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:16:38 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/18 22:27:43 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

int	split_map2(t_all *all, int i, int fd)
{
	char	*line;
	int			ret;

	ret = get_next_line(fd, &line);
	all->map.map[++i] = ft_strdup(line);
	free(line);
	/*if (i == 5)
	{
		free(all->map.map[i]);
		all->map.map[i] = NULL;
	}*/
	if (all->map.map[i] == NULL)
	{
		ft_gnl_trash(fd);
		free_map(&all->map);
		exit(EXIT_FAILURE);
	}
	return (ret);
}
