/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 22:59:09 by fcatinau          #+#    #+#             */
/*   Updated: 2021/01/09 23:00:37 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointeur, int val, size_t size)
{
	unsigned int	i;
	unsigned char	*copy;

	i = 0;
	copy = (unsigned char *)pointeur;
	while (i < size)
		copy[i++] = (unsigned char)val;
	pointeur = (void *)copy;
	return (pointeur);
}
