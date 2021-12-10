/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:19:45 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/10 11:10:08 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_v2f	project(t_v3f v, t_fdf fdf)
{
	v.x *= fdf.camera->zoom;
	v.y *= fdf.camera->zoom;
	v.z *= fdf.camera->zoom;
	v.x += fdf.window.width / 2;
	v.y -= fdf.window.height / 2;
	rotate_x(&v, fdf.camera->alpha);
	rotate_y(&v, fdf.camera->beta);
	rotate_z(&v, fdf.camera->gamma);
	if (fdf.projection == 'I')
		return (isometric_projection(v));
	else
		return (parallel_projection(v, 30));
}

static void	draw_lines(t_fdf fdf)
{
	int		x;
	int		y;
	int		color;

	y = 0;
	while (y < fdf.map->height)
	{
		x = 0;
		while (x < fdf.map->width)
		{
			color = rgb(236, 240, 241);
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

static void	draw_background(t_fdf *fdf)
{
	ft_bzero(fdf->window.img.addr, fdf->window.width * fdf->window.height
		* (fdf->window.img.bpp / 8));
}

int	render(t_fdf *fdf)
{
	draw_background(fdf);
	draw_lines(*fdf);
	mlx_put_image_to_window(fdf->window.mlx,
		fdf->window.win, fdf->window.img.mlx_img, 0, 0);
	return (0);
}
