/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:39:20 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/19 08:54:41 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"
#include <stdio.h>
int	line_in_file(char *file_name)
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

int	malloc_map(char *s, t_all *all)
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
	{
		free(all->map.map);
		error_line(line);
	}
	while (ret > 0)
	{
		all->map.map[++i] = ft_strdup(line);
		free(line);
		ret = split_map2(all, i, fd);
		printf("all->map.map[%d] = %s\n", i, all->map.map[i]);
	}
	printf("%d %s\n", 0, all->map.map[0]);
	printf("%d %s\n", 1, all->map.map[1]);
	printf("%d %s\n", 2, all->map.map[2]);
	// free(line);
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
