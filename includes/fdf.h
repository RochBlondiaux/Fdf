/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:17:45 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/23 14:09:18 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/**
 * Includes
 **/
# include "minilibx/mlx.h"
# include "libft/libft.h"
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
typedef struct s_position
{
	int	x;
	int	y;
	int	z;

}	t_position;

typedef struct s_point
{
	int			value;
	t_position	position;
}	t_point;

/**
 * Parsing
 **/
t_point	*ft_load_map(char	*filename);

/**
 * Graphics
 **/

/**
 * Utils
 **/

#endif