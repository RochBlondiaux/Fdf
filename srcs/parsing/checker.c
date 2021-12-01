/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:22:02 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/01 16:22:03 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	v3f_validate(t_v3f *a)
{
	if (!a)
	{
		perror(ERR_MAP_READING);
		exit(EXIT_FAILURE);
	}
}
