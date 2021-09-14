/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:35:22 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/26 17:16:57 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	position;
	unsigned int	i;

	if (!*to_find)
		return ((char *)str);
	position = 0;
	while (str[position] != '\0' && (size_t)position < len)
	{
		if (str[position] == to_find[0])
		{
			i = 1;
			while (to_find[i] != '\0' && str[position + i] == to_find[i]
				&& (size_t)(position + i) < len)
				++i;
			if (to_find[i] == '\0')
				return ((char *)&str[position]);
		}
		++position;
	}
	return (0);
}
