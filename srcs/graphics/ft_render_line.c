/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:08:42 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/25 15:47:43 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_render_line(t_vars *vars, t_position *p1, t_position *p2, int color)
{
	double	delta_x;
	double	delta_z;
	int		pixels;
	double	x;
	double	z;

	delta_x = p2->x - p1->x;
	delta_z = p2->z - p1->z;
	pixels = sqrt((delta_x * delta_x) + (delta_z * delta_z));
	delta_x /= pixels;
	delta_z /= pixels;
	x = p1->x;
	z = p1->z;
	while (pixels)
	{
		ft_render_pixel(&vars->img, x, z, color);
		x += delta_x;
		z += delta_z;
		--pixels;
	}
}
