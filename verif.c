/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:41:24 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/17 10:23:08 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_file_name(char *s)
{
	size_t	len;

	while (*s != '.')
		s++;
	len = ft_strlen(s);
	if (len < 4)
		len = 4;
	if (ft_strncmp(s, ".ber", len) != 0)
		return (error_msg("Bad extension file\n"));
	return (1);
}

int	verif_line(char *s, char c)
{
	while (*s)
	{
		if (*s != c)
			return (FALSE);
		s++;
	}
	return (TRUE);
}

int	verif_map(t_map *map)
{
	size_t	map_len;
	size_t	len;

	map_len = 0;
	len = ft_strlen(map->map[map_len]);
	while (map_len < map->len)
	{
		if (ft_strlen(map->map[map_len]) != len)
			return (error_msg("not a good size map\n"));
		if (map->map[map_len][0] != '1' || map->map[map_len][len - 1] != '1')
			return (error_msg("map not close by '1'\n"));
		if (map_len == 0 || map_len == map->len - 1)
			if (!verif_line(map->map[map_len], '1'))
				return (error_msg("map not close by '1'\n"));
		map_len++;
	}
	return (TRUE);
}
