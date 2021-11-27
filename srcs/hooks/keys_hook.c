/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:43:04 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/27 17:44:20 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	exit_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(vars->mlx, vars->img.mlx_img);
		mlx_destroy_window(vars->mlx, vars->win);
		free_map(vars->map);
		exit(EXIT_SUCCESS);
	}
}

int	keys_hook(int keycode, t_vars *vars)
{
	exit_hook(keycode, vars);
	return (0);
}
