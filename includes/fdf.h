/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:17:45 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/24 14:10:00 by rblondia         ###   ########.fr       */
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

/**
 * Structures
 **/
typedef struct s_point
{
	int	x;
	int	y;
	int	z;

}	t_point;

/**
 * Parsing
 **/
t_point	**ft_load_map(char	*filename);
void	ft_check_point(t_point *a);

/**
 * Graphics
 **/

/**
 * Utils
 **/
t_point	*ft_create_point(int x, char *y, int z);
size_t	ft_points_size(t_point **a);
size_t	ft_doublelenght(char **a);

#endif