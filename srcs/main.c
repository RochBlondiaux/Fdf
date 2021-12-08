/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:27:14 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/08 09:47:38 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_camera	*init_camera(void)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		exit(EXIT_FAILURE);
	camera->zoom = 10;
	return (camera);
}

void	init_window(t_fdf data)
{
	data.window.width = 1980;
	data.window.height = 1080;
	data.window.title = "FDF";
	glib_init(&data.window);
	data.camera = init_camera();
	render(&data);
	register_controls(&data);
	mlx_loop(data.window.mlx);
	free_map(data.map);
	glib_stop(&data.window);
}

int	main(int argc, char **argv)
{
	t_fdf	data;

	if (argc != 2)
	{
		perror(ERR_USAGE);
		exit(EXIT_FAILURE);
	}
	data.map = parse_map(argv[1]);
	init_window(data);
	return (0);
}
