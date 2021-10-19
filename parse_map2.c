/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:16:38 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/19 17:29:45 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

static int	line_in_file(char *file_name)
{
	int		fd;
	char	*line;
	int		nb_line;

	nb_line = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
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

static int	malloc_map(char *s, t_all *all)
{
	int	i;

	i = 0;
	all->map.len = line_in_file(s);
	if (all->map.len == -1)
		return (FAILURE);
	all->map.map = malloc(sizeof(all->map.map) * all->map.len);
	if (!all->map.map)
		return (FAILURE);
	while (i < all->map.len)
	{
		all->map.map[i] = NULL;
		i++;
	}
	return (SUCCES);
}

static void	error_line(char *line)
{
	error_msg("Empty file\n");
	free(line);
	exit (EXIT_FAILURE);
}

int	check_again(int fd, char *s, t_all *all)
{
	if (fd == -1)
		return (FAILURE);
	if (!malloc_map(s, all))
		return (FAILURE);
	return (SUCCES);
}

int	error_malloc(int ret, char *line, t_all *all)
{
	if (ret == -1)
		return (FAILURE);
	if (!*line)
	{
		free(all->map.map);
		error_line(line);
	}
	return (TRUE);
}
