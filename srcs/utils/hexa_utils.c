/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:19:45 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/10 11:10:08 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	isdigit_base(char c, int base)
{
	const char	*digits = "0123456789ABCDEF";
	int			i;

	i = 0;
	while (i < base)
	{
		if (digits[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (-1);
}

int	has_prefix(const char *str, int base)
{
	size_t	i;

	i = 0;
	if (base == 2 || base == 8 || base == 16)
	{
		if (str[i++] != '0')
			return (0);
		if ((str[i] == 'x' || str[i] == 'X'))
			return (1);
	}
	return (0);
}

int	ft_isnumber(char *str, int base)
{
	size_t		i;
	size_t		digits;

	i = 0;
	digits = 0;
	while (str[i] == ' ')
		i++;
	if (base != 10 && !has_prefix(&str[i], base))
		return (0);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		i++;
	while (isdigit_base(str[i], base) >= 0)
	{
		i++;
		digits++;
	}
	return (!str[i] && digits);
}

int	atoi_base(const char *str, int base)
{
	unsigned long	result;
	size_t			i;
	int				sign;

	if (!str)
		return (-1);
	result = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (base != 10 && !has_prefix(&str[i], base))
		return (-10124524);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		sign *= -1;
	while (isdigit_base(str[i], base) >= 0)
		result = result * base + isdigit_base(str[i++], base);
	return ((int)(result * sign));
}
