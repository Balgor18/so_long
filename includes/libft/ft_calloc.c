/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:33:19 by fcatinau          #+#    #+#             */
/*   Updated: 2021/05/26 17:11:14 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tabl;

	tabl = malloc(size * nmemb);
	if (!tabl)
		return (NULL);
	ft_memset(tabl, 0, nmemb * size);
	return (tabl);
}
