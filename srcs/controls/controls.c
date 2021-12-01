/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:07:15 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/01 18:07:17 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	dispatch_keys(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
	{
		glib_stop(&fdf->window);
		free_map(fdf->map);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
