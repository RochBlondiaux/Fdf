/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:32:35 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/23 17:04:36 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		perror(strerror(22));
		exit(1);
	}
	t_point **a = ft_load_map(argv[1]);
	int b = 0;
	while (a[b])
	{
		printf("X: %d\n", a[b]->x);
		free(a[b]);
		b++;
	}
	free(a);
	printf("POINTS: %d\n", b);	
	return (0);
}
