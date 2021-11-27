/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3f_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:02:23 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/27 13:43:05 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_v3f	vector3f(int x, int y, int z)
{
	t_v3f	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_v3f	add_v3f(t_v3f v1, t_v3f v2)
{
	return (vector3f(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

t_v3f	sub_v3f(t_v3f v1, t_v3f v2)
{
	return (vector3f(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

t_v3f	multiply_v3f(t_v3f v1, t_v3f v2)
{
	return (vector3f(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z));
}

t_v3f	normalize_v3f(t_v3f v)
{
	double	length;

	length = sqrtf (v.x * v.x + v.y * v.y + v.z * v.z);
	if (length == 0)
		return (vector3f(0, 0, 0));
	return (vector3f(v.x / length, v.y / length, v.z / length));
}
