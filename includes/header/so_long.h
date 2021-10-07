/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:51:39 by fcatinau          #+#    #+#             */
/*   Updated: 2021/10/07 19:35:29 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# if LINUX
#  include "key_keyboard_linux.h"
#  include "../mlx_linux/mlx.h"
# elif MAC_OS
#  include "key_keyboard.h"
#  include "../mlx/mlx.h"
# endif
#  include "../mlx/mlx.h"
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/gnl/get_next_line.h"

/*
** Boolean
*/
# define TRUE 1
# define FALSE 0

# define SUCCES 1
# define FAILURE 0

/*
** Height || Width
*/
# ifndef HEIGHT
#  define HEIGHT 0
# endif
# ifndef WIDTH
#  define WIDTH 0
# endif

/*
** Output FD
*/
# define STDERR 2
# define STDOUT 1

/*
** Color
*/
# define WHITE 16777215
# define ALPHA 0xff000000

/*
** ===============================================
** ===================  Struct  ==================
** ===============================================
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
	int		*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

/*
** Ennemy
*/
typedef struct s_ennemy
{
	t_img	enn0;
	t_img	enn1;
	t_img	enn2;
	t_img	enn3;
	t_img	enn4;
}				t_ennemy;
/*
** mlx
*/
typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	int			width;
	int			height;
	t_img		window;
	t_img		player;
	t_img		ground;
	t_img		wall;
	t_img		exit;
	t_img		collectible;
	t_ennemy	ennemy;
}				t_mlx;

/*
** player
*/
typedef struct s_player
{
	int	x;
	int	y;
}				t_player;

/*
** map
*/
typedef struct s_map
{
	char		**map;
	int			goal;
	int			collect;
	size_t		len;
	t_player	player;
}				t_map;

/*
** All
*/
typedef struct s_all
{
	t_map		map;
	t_mlx		mlx;
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

int		start_mlx(t_mlx *mlx, t_all *all);
void	put_texture_in_window(t_all *all);
int		press_move(t_all *all, t_map *map, char move);

/*
** ===============================================
** ==================  Texture  ==================
** ===============================================
*/
int		image_in_struct(t_all *all, t_img *i, char *file, void *mlx);
void	reset_image_put_to_window(t_all *all, int move);
int		image_to_struct(t_mlx *mlx, t_all *all);

/*
** ===============================================
** ===================  Error  ===================
** ===============================================
*/
int		error_miss_arg(void);
int		error_msg(char *s);
int		error_char(int p, int e, int c);
void	error_close(int fd, char *s);
int		error_file(char *file);

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
void	verif_width_and_height(t_all *all, t_mlx *mlx);
int		verif_map(t_map *map);

/*
** ===============================================
** ===================  Trash  ===================
** ===============================================
*/
void	ft_trash(t_all *all);
void	free_map(t_map *map);

/*
** ===============================================
** ===================  Print  ===================
** ===============================================
*/
void	print_move(t_all *all, int nb);

void	end_exit(t_all *all);
#endif
