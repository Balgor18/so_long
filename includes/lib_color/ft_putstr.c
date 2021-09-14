/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:18:16 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/12 15:22:16 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <unistd.h>

static int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (i);
	while (c[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char const *s, int fd)
{
	write(fd, s, ft_strlen((char *)s));
}
