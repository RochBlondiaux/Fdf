/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:19:45 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/08 14:40:53 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_v2f	project(t_v3f v, t_fdf fdf)
{
	v.x *= fdf.camera->zoom;
	v.y *= fdf.camera->zoom;
	v.x += fdf.window.width / 4;
	v.y -= fdf.window.height / 4;
	rotate_x(&v, fdf.camera->alpha);
	rotate_y(&v, fdf.camera->beta);
	rotate_z(&v, fdf.camera->gamma);
	return (isometric_projection(v));
}

static void	draw_lines(t_fdf fdf)
{
	int		x;
	int		y;
	t_v3f	*c;
	int		color;
	t_v3f	*previous;

	y = 0;
	while (y < fdf.map->height)
	{
		x = 0;
		while (x < fdf.map->width)
		{
			color = rgb(236, 240, 241);
			c = find_vector(fdf, x, y);
			if (!c)
				continue ;
			previous = find_vector(fdf, x - 1, y);
			if (c->z > 0)
				color = rgb(41, 128, 185);
			if (x != fdf.map->width - 1)
				draw_line(&fdf.window, project(*c, fdf),
					project(add_v3f(*c, 1, 0, 0), fdf), color);
			if (y != fdf.map->height - 1)
				draw_line(&fdf.window, project(*c, fdf),
					project(add_v3f(*c, 0, 1, 0), fdf), color);
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
