/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:22:07 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/27 16:14:12 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

size_t	v3f_lenght(t_v3f **a)
{
	size_t	size;

	if (!a)
		return (0);
	size = 0;
	while (a[size])
		size++;
	return (size);
}

size_t	double_lenght(char **a)
{
	size_t	length;

	if (!a)
		return (0);
	length = 0;
	while (a[length])
		length++;
	return (length);
}

t_v3f	*allocate_v3f(int x, int y, char *z_raw)
{
	t_v3f	*v;
	int		z;

	if (!z_raw || !z_raw[0])
		return (NULL);
	z = ft_atoi(z_raw);
	if (z == 0 && z_raw[0] != '0')
		return (NULL);
	v = malloc(sizeof(t_v3f));
	if (!v)
		return (NULL);
	v->x = x;
	v->y = y;
	v->z = z;
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
	l = v3f_lenght(a);
	c = malloc((l + v3f_lenght(b) + 1) * sizeof(t_v3f));
	if (!c)
		return (NULL);
	while (a[++i])
		c[i] = a[i];
	i = -1;
	while (b[++i])
		c[i + l] = b[i];
	c[i + l] = 0;
	if ((int) map->width > (int) i)
		map->width = i;
	free(a);
	free(b);
	return (c);
}

void	v3f_validate(t_v3f *a)
{	
	if (!a)
		printf("A\n");
	if (!a)
	{
		perror(ERR_MAP_READING);
		exit(EXIT_FAILURE);
	}
}
