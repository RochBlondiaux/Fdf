/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:17:45 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/23 15:35:22 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/**
 * Includes
 **/
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"
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

/**
 * Graphics
 **/

/**
 * Utils
 **/

#endif