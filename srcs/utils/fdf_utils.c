/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:55:08 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/23 18:21:08 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_point	*ft_create_point(int x, char *y_raw, int z)
{
	t_point	*a;
	int		y;

	if (!y_raw || !y_raw[0])
		return (NULL);
	y = ft_atoi(y_raw);
	if (y == 0 && y_raw[0] != '0')
		return (NULL);
	a = malloc(sizeof(t_point));
	if (!a)
		return (NULL);
	a->x = x;
	a->y = y;
	a->z = z;
	return (a);
}

size_t	ft_points_size(t_point **a)
{
	size_t	size;

	if (!a)
		return (0);
	size = 0;
	while (a[size])
		size++;
	return (size);
}

size_t	ft_doublelenght(char **a)
{
	size_t	length;

	length = 0;
	while (a[length])
		length++;
	return (length);
}
