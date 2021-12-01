/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:26:08 by aleferra          #+#    #+#             */
/*   Updated: 2021/11/08 16:03:09 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	i;
	unsigned int	res;
	int				neg;

	i = -1;
	res = 0;
	neg = 1;
	while (str[++i])
	{
		if (ft_isdigit(str[i]))
			res = res * 10 + str[i] - '0';
		else if (str[i] != '-')
			neg = -neg;
		else
			return (0);
	}
	if ((neg < 0 && res >= 2147483648) || res >= 2147483647)
		return (0);
	return (res * neg);
}
