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

static void	change_projection(t_fdf *fdf)
{
	if (fdf->projection == 'I')
		fdf->projection = 'P';
	else if (fdf->projection == 'P')
		fdf->projection = 'I';
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
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
	movement_control(keycode, fdf);
	rotation_control(keycode, fdf);
	return (0);
}

void	register_controls(t_fdf *fdf)
{
	register_key_hook(&fdf->window, dispatch_keys, fdf);
	mlx_hook(fdf->window.win, MOUSE_SCROLL_UP, 0, zoom, fdf);
	mlx_hook(fdf->window.win, 17, 0, close_fdf, fdf);
}
