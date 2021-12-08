/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:19:45 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/06 17:05:02 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static t_v2f	project(t_v3f v, t_fdf fdf)
{
	v.x *= fdf.camera->zoom;
	v.y *= fdf.camera->zoom;
	v.x += fdf.window.width / 2;
	v.y -= fdf.window.height / 2;
	return (isometric_projection(v));
}

static void	draw_lines(t_fdf fdf)
{
	int		x;
	int		y;
	t_v3f	*c;

	y = 0;
	while (y < fdf.map->height)
	{
		x = 0;
		while (x < fdf.map->width)
		{
			c = find_vector(fdf, x, y);
			if (!c)
				continue ;
			if (x != fdf.map->width - 1)
				draw_line(&fdf.window, project(*c, fdf),
					project(v3f(x + 1, y, c->z), fdf), rgb(236, 240, 241));
			if (y != fdf.map->height - 1)
				draw_line(&fdf.window, project(*c, fdf),
					project(v3f(x, y + 1, c->z), fdf), rgb(236, 240, 241));
			x++;
		}
		y++;
	}
}


static void	draw_background(t_fdf *fdf)
{
	ft_bzero(fdf->window.img.addr, fdf->window.width * fdf->window.height * (fdf->window.img.bpp / 8));
}

int	render(t_fdf *fdf)
{
	draw_background(fdf);
	draw_lines(*fdf);
	mlx_put_image_to_window(fdf->window.mlx,
		fdf->window.win, fdf->window.img.mlx_img, 0, 0);
	return (0);
}
