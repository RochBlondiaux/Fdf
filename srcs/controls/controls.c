/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:07:15 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/10 11:10:27 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	close_fdf(t_fdf *fdf)
{
	(void) fdf;
	exit(EXIT_SUCCESS);
}

static int	zoom(int button, int x, int y, t_fdf *fdf)
{
	(void) x;
	(void) y;
	if (button == MOUSE_SCROLL_UP)
		fdf->camera->zoom++;
	else if (button == MOUSE_SCROLL_DOWN)
		fdf->camera->zoom--;
	if (fdf->camera->zoom < 0)
		fdf->camera->zoom = 1;
	render(fdf);
	return (0);
}

static void	change_projection(t_fdf *fdf)
{
	if (fdf->projection == 'I')
		fdf->projection = 'P';
	else if (fdf->projection == 'P')
		fdf->projection = 'I';
	render(fdf);
}

int	dispatch_keys(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
	{
		glib_stop(&fdf->window);
		free(fdf->camera);
		free_map(fdf->map);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_P)
		change_projection(fdf);
	else if (keycode == KEY_LEFT)
	{
		fdf->camera->x_offset -= 10;
		render(fdf);
	}
	else if (keycode == KEY_RIGHT)
	{
		fdf->camera->x_offset += 10;
		render(fdf);
	}
	else if (keycode == KEY_UP)
	{
		fdf->camera->y_offset -= 10;
		render(fdf);
	}
	else if (keycode == KEY_DOWN)
	{
		fdf->camera->y_offset += 10;
		render(fdf);
	}
	return (0);
}

void	register_controls(t_fdf *fdf)
{
	register_key_hook(&fdf->window, dispatch_keys, fdf);
	mlx_hook(fdf->window.win, MOUSE_SCROLL_UP, 0, zoom, fdf);
	mlx_hook(fdf->window.win, 17, 0, close_fdf, fdf);
}
