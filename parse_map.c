/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:39:20 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/13 12:12:01 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

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
	free(line);
	close(fd);
	return (nb_line);
}

int	malloc_map(char *s, t_all *all)
{
	all->map.len = line_in_file(s);
	all->map.map = malloc(sizeof(all->map.map) * all->map.len);
	if (!all->map.map)
		return (FAILURE);
	return (SUCCES);
}

void	error_line(char *line)
{
	error_msg("Empty file\n");
	free(line);
	exit (EXIT_FAILURE);
}

int	split_map(char *s, t_all *all, int i)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open(s, O_RDONLY);
	if (!malloc_map(s, all))
		return (FAILURE);
	ret = get_next_line(fd, &line);
	if (ret == -1)
		return (FAILURE);
	if (!*line)
		error_line(line);
	while (ret > 0)
	{
		all->map.map[++i] = ft_strdup(line);
		if (all->map.map[i] == NULL)
		{
			free_map(&all->map);
			return (FAILURE);
		}
		free(line);
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
		error_close(fd, "Error open file\n");
	close(fd);
	fd = open(s, O_DIRECTORY);
	if (fd > 0)
		error_close(fd, "Error directory\n");
	close(fd);
	if (!split_map(s, all, -1))
		exit (EXIT_FAILURE);
	if (!verif_map(&all->map))
	{
		free_map(&all->map);
		exit (EXIT_FAILURE);
	}
	return ;
}
