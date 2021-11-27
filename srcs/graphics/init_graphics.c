/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:32:50 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/27 19:07:28 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	render(t_vars *vars)
{
	t_v3f	**vectors;
	int		index;
	int		factor;
	int		color;
	t_v2f	tmp;

	vectors = vars->map->vectors;
	index = -1;
	factor = 50;
	while (vectors[++index])
	{
		tmp = transform(vectors[index], 30);
		if (vectors[index]->z == 0)
			color = rgb(236, 240, 241);
		else
			color = rgb(231, 76, 60);
		// draw_line(vars, vector2f(vectors[index]->x * factor, vectors[index]->y * factor),
		//	vector2f(tmp.x * factor, tmp.y * factor), rgb(155, 89, 182));
		draw_rectangle(vars, vector2f(tmp.x * factor,
				tmp.y * factor),
			vector2f(tmp.x * factor + factor, tmp.y * factor + factor), color);
	}
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
