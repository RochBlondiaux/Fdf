/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:27:14 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/17 16:38:52 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "../includes/fdf.h"

t_camera	*init_camera(t_fdf fdf)
{
	t_camera	*camera;
	int			a;
	int			b;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		exit(EXIT_FAILURE);
	a = fdf.window.width / fdf.map->width / 2;
	b = fdf.window.height / fdf.map->height / 2;
	if (a < b)
		camera->zoom = a;
	else
		camera->zoom = b;
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->z_divider = 1;
	return (camera);
}

void	init(t_fdf *fdf)
{
	fdf->projection = 'I';
	fdf->camera = init_camera(*fdf);
}

int	rotate_infinity(void *f)
{
	t_fdf	*fdf;

	fdf = (t_fdf *) f;
	//fdf->camera->gamma += 0.05;
	render(fdf);
	usleep(100000);
	return (0);
}

void	init_window(t_fdf data)
{
	data.window.width = 1980;
	data.window.height = 1080;
	data.window.title = "FDF";
	glib_init(&data.window);
	init(&data);
	mlx_loop_hook(data.window.mlx, &rotate_infinity, &data);
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
	else if (!is_fdf_map(argv[1]))
	{
		perror(ERR_INVALID_EXTENSION);
		exit(EXIT_FAILURE);
	}
	data.map = parse_map(argv[1]);
	init_window(data);
	return (0);
}
