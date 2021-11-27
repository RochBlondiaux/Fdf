/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:32:35 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/27 15:55:34 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		perror(ERR_USAGE);
		exit(EXIT_FAILURE);
	}
	map = parse_map(argv[1]);
	printf("W: %d H: %d\n\n", map->width, map->height);
	int a = 0;
	while (map->vectors[a])
	{
		printf("X: %d Y: %d Z: %d\n", map->vectors[a]->x, map->vectors[a]->y, map->vectors[a]->z);
		a++;
	}
	free_map(map);
	return (EXIT_SUCCESS);
}
