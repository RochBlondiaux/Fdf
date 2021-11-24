/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:54:03 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/24 17:05:39 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	ft_exit_hook(int keycode, t_vars *vars)
{
	(void) vars;
	if (keycode == 53)
		exit(0);
	return (0);
}
