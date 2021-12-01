/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:20:25 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/01 18:34:25 by rblondia         ###   ########.fr       */
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
