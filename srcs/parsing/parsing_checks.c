/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:51:08 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/25 15:16:48 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_check_point(t_point *a)
{
	if (!a || (a->y != 0 && a->y != 10))
	{
		perror("Invalid map!");
		exit(EXIT_FAILURE);
	}
}
