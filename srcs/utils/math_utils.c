/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:21:55 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/25 18:26:25 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_position	ft_get_delta(t_position f, t_position s)
{
	t_position	d;

	d.x = abs(s.x - f.x);
	d.z = -abs(s.z - f.z);
	return (d);
}

t_position	ft_get_sign(t_position f, t_position s)
{
	t_position	sign;

	if (f.x < s.x)
		sign.x = 1;
	else
		sign.x = -1;
	if (f.z < s.z)
		sign.z = 1;
	else
		sign.z = -1;
	return (sign);
}
