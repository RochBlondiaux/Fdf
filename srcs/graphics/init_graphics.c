/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:32:50 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/27 17:07:47 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	render(t_vars *vars)
{
	draw_rectangle(vars, vector2f(150, 150), vector2f(450, 450),
		rgb(126, 214, 223));
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img.mlx_img, 0, 0);
	return (0);
}

void	init_window(t_vars *vars)
{
	if (vars->mlx == NULL)
	{
		perror(MLX_ERROR);
		exit(EXIT_FAILURE);
	}
	vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			WINDOW_TITLE);
	if (vars->win == NULL)
	{
		free(vars->win);
		perror(MLX_ERROR);
		exit(EXIT_FAILURE);
	}
}

void	init_graphics(t_vars *vars)
{
	init_window(vars);
	vars->img.mlx_img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.mlx_img, &vars->img.bpp,
			&vars->img.line_len, &vars->img.endian);
	mlx_loop_hook(vars->mlx, &render, vars);
	mlx_key_hook(vars->win, keys_hook, vars);
	mlx_loop(vars->mlx);
	mlx_destroy_image(vars->mlx, vars->img.mlx_img);
	mlx_destroy_window(vars->mlx, vars->win);
}
