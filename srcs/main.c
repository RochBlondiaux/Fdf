/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:32:35 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/27 16:36:17 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_vars	vars;

	if (argc != 2)
	{
		perror(ERR_USAGE);
		exit(EXIT_FAILURE);
	}
	vars.mlx = mlx_init();
	init_graphics(&vars);
	map = parse_map(argv[1]);
	free_map(map);
	free(vars.mlx);
	return (EXIT_SUCCESS);
}
