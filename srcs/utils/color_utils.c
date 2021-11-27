/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:17:26 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/27 17:06:03 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	rgb(int r, int g, int b)
{
	return (convert_rgba(255, r, g, b));
}

int	convert_rgba(int a, int r, int g, int b)
{
	return ((255 - a) << 24 | r << 16 | g << 8 | b);
}
