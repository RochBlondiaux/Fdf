/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c 		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:01:07 by                   #+#    #+#             */
/*   Updated: 2021/12/10 09:21:25 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static t_point	*create_point(int z, int color)
{
	t_point	*p;

	p = malloc(sizeof(t_point));
	if (!p)
		return (NULL);
	p->z = z;
	p->color = color;
	return (p);
}

void	convert_vectors(t_map *map)
{
	t_point	**cords;
	ssize_t	i;
	size_t	arr_size;
	size_t	index;

	arr_size = map->width * map->height;
	cords = malloc(sizeof(t_point *) * (arr_size + 1));
	if (!cords)
		exit(EXIT_FAILURE);
	i = map->width * map->height - 1;
	index = v3f_length(map->vectors) - 1;
	while (map->vectors[index])
	{
		cords[i] = create_point(map->vectors[index]->z,
				map->vectors[index]->color);
		if (cords[i]->z < map->z_min)
			map->z_min = cords[i]->z;
		if (cords[i]->z > map->z_max)
			map->z_max = cords[i]->z;
		i--;
		index--;
	}
	cords[arr_size] = NULL;
	map->cords = cords;
}

int	get_point_color(t_point *point, t_fdf *fdf)
{
	if (point->color == -1)
		return (get_default_color(point->z, fdf->map));
	return (point->color);
}
