/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:39:20 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/25 10:06:32 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

int	split_map(char *s, t_all *all, int i)
{
	char	*line;
	int		fd;
	int		ret;

	if (!check_again(s, all))
		return (FAILURE);
	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (FAILURE);
	ret = get_next_line(fd, &line, 0);
	if (!error_malloc(ret, line, all, fd))
		return (FAILURE);
	while (ret > 0)
	{
		all->map.map[++i] = line;
		if (all->map.map[i] == NULL)
		{
			get_next_line(fd, &line, 1);
			free_map(&all->map);
			return (FAILURE);
		}
		ret = get_next_line(fd, &line, 0);
	}
	close(fd);
	return (SUCCES);
}

void	parse_map(char *s, t_all *all)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
		error_msg("Open file\n");
	close(fd);
	fd = open(s, O_DIRECTORY);
	if (fd > 0)
		error_close(fd, "Directory\n");
	if (!split_map(s, all, -1))
		exit (EXIT_FAILURE);
	if (!verif_map(&all->map))
	{
		free_map(&all->map);
		exit (EXIT_FAILURE);
	}
	return ;
}
