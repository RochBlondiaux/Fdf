/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:17:45 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/27 16:47:06 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/**
 * Includes
 **/
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "error_messages.h"
# include "keys.h"

# include <unistd.h>
# include <stdio.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <math.h>

/**
 * Variables
 **/
# define WINDOW_WIDTH 1980
# define WINDOW_HEIGHT 1080
# define WINDOW_TITLE "FDF"
# define EXIT_SUCCESS 0

/**
 * Structures
 **/
typedef struct s_v3f
{
	int	x;
	int	y;
	int	z;
}		t_v3f;

typedef struct s_v2f {
	int	x;
	int	y;
}		t_v2f;

typedef struct s_map {
	int		height;
	int		width;
	t_v3f	**vectors;
}			t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_img	img;
}			t_vars;

/**
 * Hooks
 **/
int		keys_hook(int keycode, t_vars *vars);

/**
 * Parsing
 **/
t_map	*parse_map(char	*filename);
t_v3f	**parse_line(char *line, int y);

/**
 * Graphics
 **/
void	init_graphics(t_vars *vars);
void	draw_rectangle(t_vars *vars, t_v2f p1, t_v2f p2,
			int color);
void	draw_pixel(t_img *img, t_v2f v, int color);
void	draw_line(t_vars *vars, t_v2f f, t_v2f s, int color);

/**
 * 2D Vector
 **/
t_v2f	vector2f(int x, int y);
t_v2f	add_v2f(t_v2f v1, t_v2f v2);
t_v2f	sub_v2f(t_v2f v1, t_v2f v2);
t_v2f	multiply_v2f(t_v2f v1, t_v2f v2);
t_v2f	normalize_v2f(t_v2f v);

/**
 * 3D Vector
 **/
t_v3f	vector3f(int x, int y, int z);
t_v3f	add_v3f(t_v3f v1, t_v3f v2);
t_v3f	sub_v3f(t_v3f v1, t_v3f v2);
t_v3f	multiply_v3f(t_v3f v1, t_v3f v2);
t_v3f	normalize_v3f(t_v3f v);

/**
 * Utils
 **/
t_v2f	ft_get_delta(t_v2f f, t_v2f s);
t_v2f	ft_get_sign(t_v2f f, t_v2f s);
int		rgb(double r, double g, double b);
size_t	v3f_lenght(t_v3f **a);
size_t	double_lenght(char **a);
t_v3f	*allocate_v3f(int x, int y, char *z_raw);
void	v3f_validate(t_v3f *a);
void	free_map(t_map *map);
t_v3f	**join_v3f(t_v3f **a, t_v3f **b, t_map *map);

#endif