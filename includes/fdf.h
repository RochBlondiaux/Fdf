/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:27:19 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/17 15:38:14 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/**
 * Libraries
 */
# include "error_messages.h"
# include "keys.h"
# include "colors.h"
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../glib/includes/glib.h"
# include "../get_next_line/get_next_line.h"
# include "pthread.h"


/**
 * Structures
 */
typedef struct s_camera {
	int		zoom;
	double	alpha;
	double	beta;
	double	gamma;
	int		x_offset;
	int		y_offset;
	int		z_divider;
}			t_camera;

typedef struct s_point {
	int		z;
	int		color;
}			t_point;

typedef struct s_map {
	int			width;
	int			height;
	t_v3f		**vectors;
	t_point		**cords;
	int			z_min;
	int			z_max;
}				t_map;

typedef struct s_fdf {
	t_window	window;
	t_map		*map;
	t_camera	*camera;
	char		projection;
}				t_fdf;

/**
 * Graphics
 */
int		render(t_fdf *fdf);

/**
 * Controls
 */
void	register_controls(t_fdf *fdf);
int		dispatch_keys(int keycode, t_fdf *fdf);
int		zoom(int button, int x, int y, t_fdf *fdf);
void	movement_control(int keycode, t_fdf *fdf);
void	rotation_control(int keycode, t_fdf *fdf);

/**
 * Parsing
 */
t_map	*parse_map(char	*filename);
void	free_map(t_map *map);
void	convert_vectors(t_map *map);

/**
 * Utils
 */
size_t	v3f_length(t_v3f **a);
size_t	double_length(char **a);
t_v3f	*allocate_v3f(int x, int y, char *z_raw);
t_v3f	**join_v3f(t_v3f **a, t_v3f **b, t_map *map);
void	v3f_validate(t_v3f *a);
t_v3f	new_3d_point(int x, int y, t_map *map);
int		get_default_color(int z, t_map *map);
int		get_index(int x, int y, int width);
int		is_empty(char *str);
int		atoi_base(const char *str, int base);
int		is_fdf_map(char *filename);
t_v3f	*create_vector3f(int x, int y, int z, int color);
int		get_point_color(t_point *point, t_fdf *fdf);

#endif