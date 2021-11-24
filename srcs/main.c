/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:32:35 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/24 16:56:41 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../srcs/mlx/mlx.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	(void) argv;
	if (argc != 2)
	{
		perror(strerror(22));
		exit(1);
	}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FDF");
	mlx_key_hook(vars.win, ft_exit_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
