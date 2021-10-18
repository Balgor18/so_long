/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:41:24 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/18 15:04:09 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header/so_long.h"

int	verif_file_name(char *s)
{
	size_t	len;

	if (s[0] == '.')
		s++;
	while (*s != '.')
		s++;
	if (*s == '.' && *(s - 1) == '/')
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

int	verif_char_map(t_map *map, char *s, t_char_map *sc, int y)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == 'C')
			sc->count_c++;
		if (s[i] == 'P')
		{
			map->player.x = i;
			map->player.y = y;
			sc->count_p++;
		}
		if (s[i] == 'E')
			sc->count_e++;
		if (s[i] != 'C' && s[i] != '1' && s[i] != '0'
			&& s[i] != 'E' && s[i] != 'P')
			return (error_msg("Bad characther in map\n"));
	}
	return (TRUE);
}

int	verif_map(t_map *map)
{
	size_t		map_len;
	size_t		len;
	t_char_map	cm;

	init_char_map(&cm);
	map_len = 0;
	len = ft_strlen(map->map[map_len]);
	while (map_len < map->len)
	{
		if (!verif_char_map(map, map->map[map_len], &cm, map_len))
			return (FALSE);
		if (ft_strlen(map->map[map_len]) != len)
			return (error_msg("not a good size map\n"));
		if (map->map[map_len][0] != '1' || map->map[map_len][len - 1] != '1')
			return (error_msg("map not close by '1'\n"));
		if (map_len == 0 || map_len == map->len - 1)
			if (!verif_line(map->map[map_len], '1'))
				return (error_msg("map not close by '1'\n"));
		map_len++;
	}
	if (cm.count_c == 0 || cm.count_e == 0 || cm.count_p == 0 || cm.count_p > 1)
		return (error_char(cm.count_p, cm.count_e, cm.count_c));
	map->goal = cm.count_c;
	return (TRUE);
}
