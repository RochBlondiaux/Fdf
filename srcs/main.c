/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:27:14 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/01 15:27:15 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_window(t_fdf data)
{
	data.window.width = 1980;
	data.window.height = 1080;
	data.window.title = "FDF";
	glib_start(&data.window);
}

int	main(int argc, char **argv)
{
	t_fdf	data;

	if (argc != 2)
	{
		perror(ERR_USAGE);
		exit(EXIT_FAILURE);
	}
	data.map = parse_map(argv[1]);
	init_window(data);
	free_map(data.map);
	return (0);
}
