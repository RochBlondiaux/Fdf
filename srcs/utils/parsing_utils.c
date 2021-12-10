/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:25:02 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/10 18:47:50 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

size_t	v3f_length(t_v3f **a)
{
	size_t	size;

	if (!a)
		return (0);
	size = 0;
	while (a[size])
		size++;
	return (size);
}

size_t	double_length(char **a)
{
	size_t	length;

	if (!a)
		return (0);
	length = 0;
	while (a[length])
		length++;
	return (length);
}

static void	free_parts(char **parts)
{
	int	i;

	i = 0;
	while (parts[i])
	{
		free(parts[i]);
		i++;
	}
	free(parts);
}

t_v3f	*allocate_v3f(int x, int y, char *z_raw)
{
	t_v3f	*v;
	int		z;
	char	**parts;

	if (!z_raw || ft_strlen(z_raw) <= 0)
		return (NULL);
	parts = ft_split(z_raw, ',');
	if (!parts)
		return (NULL);
	z = ft_atoi(parts[0]);
	if ((z == -1 && parts[0][0] != '-'))
	{
		free_parts(parts);
		return (NULL);
	}
	v = create_vector3f(x, y, z, atoi_base(parts[1], 16));
	free_parts(parts);
	if (!v)
		return (NULL);
	return (v);
}

t_v3f	**join_v3f(t_v3f **a, t_v3f **b, t_map *map)
{
	t_v3f	**c;
	size_t	i;
	size_t	l;

	if (!a || !b)
		return (NULL);
	i = -1;
	l = v3f_length(a);
	c = malloc((l + v3f_length(b) + 1) * sizeof(t_v3f));
	if (!c)
		return (NULL);
	while (a[++i])
		c[i] = a[i];
	i = -1;
	while (b[++i])
		c[i + l] = b[i];
	c[i + l] = 0;
	if ((int) map->width < (int) i)
		map->width = i;
	free(a);
	free(b);
	return (c);
}
