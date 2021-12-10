/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:20:25 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/10 11:10:57 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_v3f	*find_vector(t_fdf fdf, int x, int y)
{
	int		i;
	t_v3f	**v;

	i = -1;
	v = fdf.map->vectors;
	while (v[++i])
	{
		if (v[i]->x == x && v[i]->y == y)
			return (v[i]);
	}
	return (NULL);
}

static int	get_index(int x, int y, int width)
{
	return (y * width + x);
}

t_v3f	new_3d_point(int x, int y, t_map *map)
{
	t_v3f	point;
	int		index;

	index = get_index(x, y, map->width);
	point.x = x;
	point.y = y;
	point.z = map->cords[index];
	return (point);
}
