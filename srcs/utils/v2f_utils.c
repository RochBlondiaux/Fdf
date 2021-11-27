/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2f_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:54:30 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/27 13:09:04 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_v2f	vector2f(int x, int y)
{
	t_v2f	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_v2f	add_v2f(t_v2f v1, t_v2f v2)
{
	return (vector2f(v1.x + v2.x, v1.y + v2.y));
}

t_v2f	sub_v2f(t_v2f v1, t_v2f v2)
{
	return (vector2f(v1.x - v2.x, v1.y - v2.y));
}

t_v2f	multiply_v2f(t_v2f v1, t_v2f v2)
{
	return (vector2f(v1.x * v2.x, v1.y * v2.y));
}

t_v2f	normalize_v2f(t_v2f v)
{
	double	length;

	length = sqrtf (v.x * v.x + v.y * v.y);
	if (length == 0)
		return (vector2f(0, 0));
	return (vector2f(v.x / length, v.y / length));
}
