/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:26:08 by aleferra          #+#    #+#             */
/*   Updated: 2021/12/08 18:06:17 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	i;
	unsigned int	res;
	int				neg;

	i = 0;
	res = 0;
	neg = 1;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			res = res * 10 + str[i] - '0';
		else if (str[i] == '-')
			neg = -1;
		else
			return (0);
		i++;
	}
	if ((neg < 0 && res >= 2147483648) || res >= 2147483647)
		return (0);
	return (res * neg);
}
