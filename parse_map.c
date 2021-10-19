/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:39:20 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/19 17:29:38 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

int	split_map(char *s, t_all *all, int i)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open(s, O_RDONLY);
	if (!check_again(fd, s, all))
		return (FAILURE);
	ret = get_next_line(fd, &line);
	if (!error_malloc(ret, line, all))
		return (FAILURE);
	while (ret > 0)
	{
		all->map.map[++i] = ft_strdup(line);
		free(line);
		if (all->map.map[i] == NULL)
		{
			ft_gnl_trash(fd);
			free_map(&all->map);
			return (FAILURE);
		}
		ret = get_next_line(fd, &line);
	}
	free(line);
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
