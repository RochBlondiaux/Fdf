/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:22:04 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/10 09:18:38 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_map	*create_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	return (map);
}

t_v3f	**parse_line(char *line, int y)
{
	t_v3f	**vectors;
	char	**s;
	int		i;
	t_v3f	*tmp;

	if (!line)
		return (NULL);
	s = ft_split(line, ' ');
	i = 0;
	vectors = malloc(sizeof(t_v3f *) * (double_length(s) + 1));
	if (!vectors)
		return (NULL);
	while (s[i])
	{
		tmp = allocate_v3f(i, y, s[i]);
		v3f_validate(tmp);
		vectors[i] = tmp;
		free(s[i]);
		i++;
	}
	free(s);
	free(line);
	vectors[i] = 0;
	return (vectors);
}

t_map	*parse_file(int fd)
{
	t_map	*map;
	t_v3f	**vectors;
	t_v3f	**c;
	char	*tmp;

	tmp = get_next_line(fd);
	map = create_map();
	map->height = 0;
	vectors = parse_line(tmp, map->height);
	map->height++;
	while (tmp)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		c = parse_line(tmp, map->height);
		vectors = join_v3f(vectors, c, map);
		map->height++;
	}
	close(fd);
	map->vectors = vectors;
	return (map);
}

t_map	*parse_map(char	*filename)
{
	int		fd;
	t_map	*map;

	if (!filename)
	{
		perror(strerror(2));
		exit(EXIT_FAILURE);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror(strerror(9));
		exit(EXIT_FAILURE);
	}
	map = parse_file(fd);
	if (!map)
	{
		perror(ERR_MAP);
		exit(EXIT_FAILURE);
	}
	convert_vectors(map);
	return (map);
}

void	free_map(t_map *map)
{
	int	index;

	index = 0;
	while (map->vectors[index])
	{
		free(map->vectors[index]);
		index++;
	}
	free(map->cords);
	free(map->vectors);
	free(map);
}
