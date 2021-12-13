/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:19:45 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/13 11:04:16 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static t_v2f	project(t_v3f v, t_fdf fdf)
{
	t_v2f	vector;

	v.x *= fdf.camera->zoom;
	v.y *= fdf.camera->zoom;
	v.z *= fdf.camera->zoom / fdf.camera->z_divider;
	v.x -= (fdf.map->width * fdf.camera->zoom) / 2;
	v.y -= (fdf.map->height * fdf.camera->zoom) / 2;
	rotate_x(&v, fdf.camera->alpha);
	rotate_y(&v, fdf.camera->beta);
	rotate_z(&v, fdf.camera->gamma);
	if (fdf.projection == 'I')
		vector = isometric_projection(v);
	else
		vector = parallel_projection(v, 30);
	vector.x += fdf.window.width / 2 + fdf.camera->x_offset;
	vector.y += (fdf.window.height + fdf.map->height * fdf.camera->zoom)
		/ 2 + fdf.camera->y_offset;
	return (vector);
}

static void	draw_lines(t_fdf fdf)
{
	int		x;
	int		y;
	t_point	*point;
	int		color;

	y = 0;
	while (y < fdf.map->height)
	{
		x = 0;
		while (x < fdf.map->width)
		{
			point = fdf.map->cords[get_index(x, y, fdf.map->width)];
			color = get_point_color(point, &fdf);
			if (x != fdf.map->width - 1)
				draw_line(&fdf.window, project(new_3d_point(x, y,
							fdf.map), fdf), project(new_3d_point(x + 1, y,
							fdf.map), fdf), color);
			if (y != fdf.map->height - 1)
				draw_line(&fdf.window, project(new_3d_point(x, y,
							fdf.map), fdf), project(new_3d_point(x, y + 1,
							fdf.map), fdf), color);
			x++;
		}
		y++;
	}
}

static void	clear_image(t_fdf *fdf)
{
	int	y;
	int	x;

	y= 0;
	while (y < fdf->window.height)
	{
		x = 0;
		while (x < fdf->window.width)
		{
			draw_pixel(&fdf->window, v2f(x, y), BACKGROUND);
			x++;
		}
		y++;
	}
}

int	render(t_fdf *fdf)
{
	clear_image(fdf);
	draw_lines(*fdf);
	mlx_put_image_to_window(fdf->window.mlx,
		fdf->window.win, fdf->window.img.mlx_img, 0, 0);
	return (0);
}
