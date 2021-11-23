/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:06:10 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/09 17:56:14 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void			*new;	
	size_t			i;

	i = 0;
	new = malloc(nelem * elsize);
	if (!new)
		return (NULL);
	ft_bzero(new, (nelem * elsize));
	return (new);
}
