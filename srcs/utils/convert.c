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

void	convert_vectors(t_map *map)
{
	int		*cords;
	ssize_t	i;
	size_t	arr_size;
	size_t	index;

	arr_size = map->width * map->height * sizeof(int);
	cords = malloc(sizeof(int) * arr_size);
	if (!cords)
		exit(EXIT_FAILURE);
	i = map->width * map->height - 1;
	index = v3f_length(map->vectors) - 1;
	while (map->vectors[index] && index > 0)
	{
		cords[i] = map->vectors[index]->z;
		i--;
		index--;
	}
	map->cords = cords;
}
