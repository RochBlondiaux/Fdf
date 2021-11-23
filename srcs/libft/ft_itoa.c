/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:03:10 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/09 18:03:13 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strlen_number(int n)
{
	int				i;
	unsigned int	nb;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		nb = -n;
		i++;
	}
	else
		nb = n;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static unsigned int	ft_abs(int n)
{
	if (n < 0)
		return ((unsigned int)-n);
	return (n);
}

char	*ft_itoa(int n)
{
	int				strlen;
	unsigned int	nb;
	char			*number;

	strlen = strlen_number(n);
	number = malloc(sizeof(char) * (strlen + 1));
	if (!number)
		return (NULL);
	if (n < 0)
		number[0] = '-';
	nb = ft_abs(n);
	number[strlen--] = '\0';
	if (nb == 0)
		number[strlen] = '0';
	else
	{
		while (nb != 0)
		{
			number[strlen--] = nb % 10 + '0';
			nb = nb / 10;
		}
	}
	return (number);
}
