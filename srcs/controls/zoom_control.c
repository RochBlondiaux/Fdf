/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:07:15 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/10 11:10:27 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	zoom(int button, int x, int y, t_fdf *fdf)
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
