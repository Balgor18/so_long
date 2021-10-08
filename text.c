/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:55:56 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/08 10:59:04 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libc.h>

int	main(int agc, char **agv)
{
	char	*s;

	s = malloc(sizeof(char) * 100000);
	if (!*s)
		return (EXIT_FAILURE);
	s[100000] = '\0';
	while (*s)
	{
		printf("je fais ceque je veux dedans\n");
		s++;
	}
	return (EXIT_SUCCESS);
}
