/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:57:01 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/25 14:16:02 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	rgb_to_int(double r, double g, double b)
{
	int	color;

	color = 0;
	color |= (int)(b * 255);
	color |= (int)(g * 255) << 8;
	color |= (int)(r * 255) << 16;
	return (color);
}

int	ft_get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int	ft_get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int	ft_get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int	ft_get_b(int trgb)
{
	return (trgb & 0xFF);
}
