/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:27:19 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/08 13:19:29 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/**
 * Libraries
 */
# include "error_messages.h"
# include "keys.h"
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../glib/includes/glib.h"
# include "../get_next_line/get_next_line.h"

/**
 * Structures
 */
typedef struct s_camera {
	int		zoom;
	int		alpha;
	int		beta;
	int		gamma;
}			t_camera;

typedef struct s_map {
	int			width;
	int			height;
	t_v3f		**vectors;
}				t_map;

typedef struct s_fdf {
	t_window	window;
	t_map		*map;
	t_camera	*camera;
}				t_fdf;

/**
 * Graphics
 */
int		render(t_fdf *fdf);
t_v2f	project(t_v3f v, t_fdf fdf);

/**
 * Controls
 */
void	register_controls(t_fdf *fdf);
int		dispatch_keys(int keycode, t_fdf *fdf);

/**
 * Parsing
 */
t_map	*parse_map(char	*filename);
void	free_map(t_map *map);

/**
 * Utils
 */
size_t	v3f_length(t_v3f **a);
size_t	double_length(char **a);
t_v3f	*allocate_v3f(int x, int y, char *z_raw);
t_v3f	**join_v3f(t_v3f **a, t_v3f **b, t_map *map);
void	v3f_validate(t_v3f *a);
t_v3f	*find_vector(t_fdf fdf, int x, int y);
int		is_inside(t_v3f *p, t_v3f *c, int type, t_fdf fdf);

#endif