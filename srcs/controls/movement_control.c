/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:07:15 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/10 11:10:27 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	movement_control(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_LEFT)
		fdf->camera->x_offset -= 10;
	else if (keycode == KEY_RIGHT)
		fdf->camera->x_offset += 10;
	else if (keycode == KEY_UP)
		fdf->camera->y_offset -= 10;
	else if (keycode == KEY_DOWN)
		fdf->camera->y_offset += 10;
	else
		return ;
	render(fdf);
}
