/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:08:42 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/25 18:28:04 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_render_line(t_vars *vars, t_position f, t_position s, int color)
{
	t_position	delta;
	t_position	sign;
	t_position	current;
	int			error[2];

	delta = ft_get_delta(f, s);
	sign = ft_get_sign(f, s);
	error[0] = delta.x + delta.z;
	current = f;
	while (current.x != s.x || current.z != s.z)
	{
		ft_render_pixel(&vars->img, current.x, current.z, color);
		error[1] = 2 * error[0];
		if (error[1] >= delta.z)
		{
			error[0] += delta.z;
			current.x += sign.x;
		}
		if (error[1] <= delta.x)
		{
			error[0] += delta.x;
			current.z += sign.z;
		}
	}
}
