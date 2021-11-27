/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:28:30 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/27 18:54:39 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	draw_rectangle(t_vars *vars, t_v2f p1, t_v2f p2,
	int color)
{
	draw_line(vars, vector2f(p1.x, p1.y),
		vector2f(p2.x, p1.y), color);
	draw_line(vars, vector2f(p1.x, p1.y),
		vector2f(p1.x, p2.y), color);
	draw_line(vars, vector2f(p1.x, p2.y),
		vector2f(p2.x, p2.y), color);
	draw_line(vars, vector2f(p2.x, p2.y),
		vector2f(p2.x, p1.y), color);
}
