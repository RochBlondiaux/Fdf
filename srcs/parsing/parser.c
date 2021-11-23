/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:36:01 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/23 17:05:18 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

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

t_point	**ft_join_points(t_point **a, t_point **b)
{
	t_point	**c;
	size_t	i;
	size_t	l;

	if (!a || !b)
		return (NULL);
	i = 0;
	l = ft_points_size(a);
	c = malloc((l + ft_points_size(b) + 1) * sizeof(t_point *));
	if (!c)
		return (NULL);
	while (a[i])
	{
		c[i] = a[i];
		i++;
	}
	i = 0;
	while (b[i])
	{
		c[i + l] = b[i];
		i++;
	}
	c[i + l] = 0;
	free(a);
	free(b);
	return (c);
}

t_point	**ft_parse_line(char *line, int z)
{
	t_point	**points;
	t_point	*tmp;
	char	**s;
	int		i;
	int		l;

	if (!line)
		return (NULL);
	s = ft_split(line, ' ');
	l = 0;
	while (s[l])
		l++;
	i = 0;
	points = malloc(sizeof(t_point *) * l);
	if (!points)
		return (NULL);
	while (s[i])
	{
		tmp = malloc(sizeof(t_point *));
		if (!tmp)
			return (NULL);
		tmp->x = i;
		tmp->y = ft_atoi(s[i]);
		tmp->z = z;
		points[i] = tmp;
		free(s[i]);
		i++;
	}
	free(s);
	free(line);
	points[i] = 0;
	return (points);
}

t_point	**ft_parse_file(int fd)
{
	int		z;
	char	*tmp;
	t_point	**points;
	t_point	**c;

	z = 0;
	tmp = get_next_line(fd);
	points = ft_parse_line(tmp, z);
	z++;
	while (tmp)
	{
		tmp = get_next_line(fd);
		c = ft_parse_line(tmp, z);
		if (!c)
			break ;
		points = ft_join_points(points, c);
		z++;
	}
	close(fd);
	return (points);
}

t_point	**ft_load_map(char	*filename)
{
	int	fd;

	if (!filename)
	{
		perror(strerror(2));
		exit(1);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror(strerror(9));
		exit(1);
	}
	return (ft_parse_file(fd));
}
