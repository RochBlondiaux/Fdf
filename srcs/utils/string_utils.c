/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:22:04 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/10 11:10:48 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	is_empty(char *str)
{
	int	i;

	if (!str || ft_strlen(str) == 0)
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	is_fdf_map(char *filename)
{
	size_t	size;

	if (!filename || ft_strlen(filename) < 4)
		return (0);
	size = ft_strlen(filename) - 1;
	return (filename[size] == 'f' && filename[size - 1] == 'd'
		&& filename[size - 2] == 'f' && filename[size - 3] == '.');
}

t_v3f	*create_vector3f(int x, int y, int z, int color)
{
	t_v3f	*v;

	v = malloc(sizeof(t_v3f));
	if (!v)
		return (NULL);
	v->x = x;
	v->y = y;
	v->z = z;
	v->color = color;
	return (v);
}
