/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_rectangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:28:30 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/27 12:54:23 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_render_rectangle(t_vars *vars, t_v2f p1, t_v2f p2,
	int color)
{
	ft_render_line(vars, ft_create_position(p1.x, p1.z),
		ft_create_position(p2.x, p1.z), color);
	ft_render_line(vars, ft_create_position(p1.x, p1.z),
		ft_create_position(p1.x, p2.z), color);
	ft_render_line(vars, ft_create_position(p1.x, p2.z),
		ft_create_position(p2.x, p2.z), color);
	ft_render_line(vars, ft_create_position(p2.x, p2.z),
		ft_create_position(p2.x, p1.z), color);
}
