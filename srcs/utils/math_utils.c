/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:12:28 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/27 18:53:25 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_v2f	get_delta(t_v2f f, t_v2f s)
{
	return (vector2f(abs(s.x - f.x), -abs(s.y - f.y)));
}

t_v2f	get_sign(t_v2f f, t_v2f s)
{
	t_v2f	sign;

	if (f.x < s.x)
		sign.x = 1;
	else
		sign.x = -1;
	if (f.y < s.y)
		sign.y = 1;
	else
		sign.y = -1;
	return (sign);
}

t_v2f	transform(t_v3f *v, int angle)
{
	return (vector2f(v->x + cos(angle) * v->z - cos(angle) * v->y,
			-v->y * sin(angle) - v->z * sin(angle)));
}
