/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:20:25 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/08 14:17:17 by rblondia         ###   ########.fr       */
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

int	intersect(t_v2f p0, t_v2f p1, t_v2f c0, t_v2f c1)
{
	t_v2f	m;

	if (p0.x == p1.x)
		return (!(c0.x == c1.x && p1.x != c0.x));
	else if (c0.x == c1.x)
		return (1);
	else
	{
		m = v2f((p0.y - p1.y) / (p0.x - p1.x),
				(c0.y - c1.y) / (c0.x - c1.x));
		return (m.x == m.y);
	}
}

int	is_inside(t_v3f *p, t_v3f *c, int type, t_fdf fdf)
{
	t_v2f	p1;
	t_v2f	p2;
	t_v2f	c1;
	t_v2f	c2;

	if (!p || !c || p->z == c->z)
		return (0);
	p1 = project(*p, fdf);
	c1 = project(*c, fdf);
	if (type == 1)
	{
		p2 = project(add_v3f(*p, 1, 0, 0), fdf);
		c2 = project(add_v3f(*c, 1, 0, 0), fdf);
	}
	else
	{
		p2 = project(add_v3f(*p, 0, 1, 0), fdf);
		c2 = project(add_v3f(*c, 0, 1, 0), fdf);
	}
	return (intersect(p1, p2, c1, c2));
}
