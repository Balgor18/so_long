/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:41:24 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/15 15:16:49 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_file_name(char *s)
{
	while (*s != '.')
		s++;
	if (ft_strncmp(s, ".ber", ft_strlen(s)) != 0)
		return (error_msg("Bad extension file\n"));
	return (1);
}
