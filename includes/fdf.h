/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:17:45 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/25 16:30:02 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/**
 * Includes
 **/
# include "../srcs/mlx/mlx.h"
# include "../srcs/libft/libft.h"
# include "../srcs/gnl/get_next_line.h"
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
# define KEY_ESC 53
# define WINDOW_WIDTH 1980
# define WINDOW_HEIGHT 1080
# define WINDOW_TITLE "FDF"
# define EXIT_SUCCESS 0

/**
 * Structures
 **/
typedef struct s_point
{
	int	x;
	int	y;
	int	z;

}	t_point;

typedef struct s_position {
	int	x;
	int	z;
}	t_position;

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
}	t_vars;

/**
 * Hooks
 **/
int			ft_exit_hook(int keycode, t_vars *vars);

/**
 * Parsing
 **/
t_point		**ft_load_map(char	*filename);
void		ft_check_point(t_point *a);

/**
 * Graphics
 **/
void		ft_render_pixel(t_img *img, int x, int y, int color);
void		ft_render_line(t_vars *vars, t_position p1,
				t_position p2, int color);
void		ft_render_rectangle(t_vars *vars, t_position p1, t_position p2,
				int color);

/**
 * Utils
 **/
t_point		*ft_create_point(int x, char *y, int z);
size_t		ft_points_size(t_point **a);
size_t		ft_doublelenght(char **a);
t_position	ft_create_position(int x, int z);
int			rgb_to_int(double r, double g, double b);
t_position	ft_get_delta(t_position f, t_position s);
t_position	ft_get_sign(t_position f, t_position s);

#endif