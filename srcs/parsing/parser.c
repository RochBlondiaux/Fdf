/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:36:01 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/23 14:14:46 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_point	*ft_parse_file(int fd)
{
	(void) fd;
	return (NULL);
}

t_point	*ft_load_map(char	*filename)
{
	int	fd;

	if (!filename)
	{
		perror(strerror(2));
		exit(1);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror(strerror(9));
		exit(1);
	}
	return (ft_parse_file(fd));
}