/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 22:52:32 by fcatinau          #+#    #+#             */
/*   Updated: 2021/01/09 22:52:33 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	c;
	long			nb;

	nb = size;
	i = ft_strlen(dest);
	if (size == 0)
		return (ft_strlen(src));
	c = 0;
	while (src[c] && (c + i) < (nb - 1))
	{
		dest[i + c] = src[c];
		c++;
	}
	if (size < i)
		return (ft_strlen(src) + size);
	if (c < size)
		dest[i + c] = '\0';
	return (ft_strlen(src) + i);
}
