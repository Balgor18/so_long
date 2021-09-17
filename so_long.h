/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:51:39 by fcatinau          #+#    #+#             */
/*   Updated: 2021/09/17 20:02:39 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "includes/libft/libft.h"
# include "includes/mlx/mlx.h"
# include "includes/libft/gnl/get_next_line.h"

# define TRUE 1
# define FALSE 0

# define SUCCES 1
# define FAILURE 0

# define STDERR 2
# define STDOUT 1

/*
** ===============================================
** ===================  Struct  ==================
** ===============================================
*/

/*
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
*/

typedef struct s_char_map
{
	int	count_p;
	int	count_e;
	int	count_c;
}				t_char_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

/*
** mlx
*/
typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
//	void	*mlx_img;
}				t_mlx;

/*
** map
*/
typedef struct s_map
{
	char	**map;
	size_t	len;
}				t_map;

/*
** All
*/
typedef struct s_all
{
	t_map	map;
	t_mlx	mlx;
}				t_all;

/*
** ===============================================
** ===================  Init  ====================
** ===============================================
*/
void	init_struct(t_all *all);
void	init_char_map(t_char_map *cm);

/*
** ===============================================
** ====================  Mlx  ====================
** ===============================================
*/
//void	start_mlx(t_all *all);
void	start_mlx(t_mlx *mlx, t_all *all);
/*
** ===============================================
** ===================  Error  ===================
** ===============================================
*/
int		error_miss_arg(void);
int		error_msg(char *s);
int		error_char(int p, int e, int c);

/*
** ===============================================
** ===================  Parse  ===================
** ===============================================
*/
void	parse_map(char *s, t_all *all);

/*
** ===============================================
** ===================  Verif  ===================
** ===============================================
*/
int		verif_file_name(char *s);

/*
** ===============================================
** ===================  Trash  ===================
** ===============================================
*/
void	ft_trash(t_all *all);
void	free_map(t_map *map);

/*
** ===============================================
** ===================  Error  ===================
** ===============================================
*/
int		error_miss_arg(void);
int		error_msg(char *s);

/*
** ===============================================
** ===================  Verif  ===================
** ===============================================
*/
int		verif_file_name(char *s);
int		verif_map(t_map *map);

#endif
