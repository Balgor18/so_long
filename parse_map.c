/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:39:20 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/15 18:41:00 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_in_file(char *file_name)
{
	int		fd;
	char	*line;
	int		nb_line;

	nb_line = 0;
	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		nb_line++;
		free(line);
	}
	if (line)
		free(line);
	close(fd);
	return (nb_line);
}

int	split_map(char *s, t_all *all)
{
	char	*line;
	int		fd;
	int		i;

	all->map.len = line_in_file(s);
	i = -1;
	fd = open(s, O_RDONLY);
	all->map.map = malloc(sizeof(all->map.map) * all->map.len);
	if (!all->map.map)
		return (FAILURE);
	while (get_next_line(fd, &line) > 0)
	{
		all->map.map[++i] = ft_strdup(line);
		free(line);
	}
	if (line)
		free(line);
	return (SUCCES);
}

int	parse_map(char *s, t_all *all)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (error_msg("Error open file\n"));
	}
	close(fd);
	split_map(s, all);
	return (TRUE);
}
