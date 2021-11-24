/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:32:35 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/24 14:18:30 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../srcs/mlx/mlx.h"

int	main(int argc, char **argv)
{
	void	*mlx;

	(void) argv;
	if (argc != 2)
	{
		perror(strerror(22));
		exit(1);
	}
	mlx = mlx_init();
	return (0);
}
