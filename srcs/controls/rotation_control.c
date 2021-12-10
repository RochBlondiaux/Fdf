/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:07:15 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/10 11:10:27 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	rotation_control(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_1)
		fdf->camera->alpha += 0.05;
	else if (keycode == KEY_2)
		fdf->camera->alpha -= 0.05;
	else if (keycode == KEY_3)
		fdf->camera->beta += 0.05;
	else if (keycode == KEY_4)
		fdf->camera->beta -= 0.05;
	else if (keycode == KEY_5)
		fdf->camera->gamma += 0.05;
	else if (keycode == KEY_6)
		fdf->camera->gamma -= 0.05;
	else if (keycode == KEY_7)
		fdf->camera->z_divider += 1;
	else if (keycode == KEY_8 && fdf->camera->z_divider > 1)
		fdf->camera->z_divider -= 1;
	else
		return ;
	render(fdf);
}
