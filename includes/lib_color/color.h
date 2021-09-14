/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 09:57:34 by fcatinau          #+#    #+#             */
/*   Updated: 2021/08/13 11:47:29 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <unistd.h>

/*
** putstr
*/
void	ft_putstr_fd(char const *s, int fd);

/*
** Test
*/
void	test(void);

void	black(void);
void	blue(void);
void	cyan(void);
void	green(void);

void	purple(void);
void	red(void);
void	white(void);
void	yellow(void);

void	reset(void);

#endif
