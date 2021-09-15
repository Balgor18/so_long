/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:41:24 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/15 16:03:53 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_file_name(char *s)
{
	size_t	len;

	while (*s != '.')
		s++;
	len = ft_strlen(s);
	if (len < ft_strlen(".ber"))
		len = ft_strlen(".ber");
	if (ft_strncmp(s, ".ber", len) != 0)
		return (error_msg("Bad extension file\n"));
	return (1);
}
