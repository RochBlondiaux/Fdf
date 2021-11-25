/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:32:35 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/25 15:48:51 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../srcs/mlx/mlx.h"

int	render(t_vars	*vars)
{
	if (vars->win == NULL)
		return (1);
	ft_render_line(vars, ft_create_position(1980, 1080), ft_create_position(0, 0), 0xFFFFFF);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img.mlx_img, 0, 0);
	return (0);
}

void	setup_image(t_vars *vars)
{
	vars->img.mlx_img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.mlx_img, &vars->img.bpp,
			&vars->img.line_len, &vars->img.endian);
	mlx_loop_hook(vars->mlx, &render, vars);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	(void) argv;
	if (argc != 2)
	{
		perror(strerror(22));
		exit(EXIT_FAILURE);
	}
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (EXIT_FAILURE);
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			WINDOW_TITLE);
	if (vars.win == NULL)
	{
		free(vars.win);
		return (EXIT_FAILURE);
	}
	mlx_key_hook(vars.win, ft_exit_hook, &vars);
	setup_image(&vars);
	mlx_loop(vars.mlx);
	mlx_destroy_image(vars.mlx, vars.img.mlx_img);
	mlx_destroy_window(vars.mlx, vars.win);
	free(vars.mlx);
	return (EXIT_SUCCESS);
}
