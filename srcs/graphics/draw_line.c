/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:08:42 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/27 16:40:54 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	draw_line(t_vars *vars, t_v2f f, t_v2f s, int color)
{
	t_v2f	delta;
	t_v2f	sign;
	t_v2f	current;
	int		error[2];

	delta = ft_get_delta(f, s);
	sign = ft_get_sign(f, s);
	error[0] = delta.x + delta.y;
	current = f;
	while (current.x != s.x || current.y != s.y)
	{
		draw_pixel(&vars->img, current, color);
		error[1] = 2 * error[0];
		if (error[1] >= delta.y)
		{
			error[0] += delta.y;
			current.x += sign.x;
		}
		if (error[1] <= delta.x)
		{
			error[0] += delta.x;
			current.y += sign.y;
		}
	}
}
