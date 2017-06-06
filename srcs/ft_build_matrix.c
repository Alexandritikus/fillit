/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:19:30 by oshudria          #+#    #+#             */
/*   Updated: 2016/12/16 14:02:14 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_square_size(int amount)
{
	int	sq_size;
	int	n_dashes;

	n_dashes = amount * 4;
	sq_size = 1;
	while (sq_size * sq_size < n_dashes)
		sq_size++;
	return (sq_size);
}

static t_square	*ft_create_square(t_square *map, int sq_size)
{
	int	sq_len;
	int	i;

	if ((map = (t_square*)malloc(sizeof(t_square))) == NULL)
		ft_puterror(0);
	map->size = sq_size;
	sq_len = sq_size * (sq_size + 1);
	if ((map->str = (char*)malloc(sizeof(char) * (sq_len + 1))) == NULL)
		ft_puterror(0);
	map->str[sq_len] = '\0';
	map->str = (char*)ft_memset(map->str, '.', sq_len);
	i = 1;
	while (map->str[i - 1] != '\0')
	{
		if (i % (sq_size + 1) == 0)
			map->str[i - 1] = '\n';
		i++;
	}
	return (map);
}

t_square		*ft_build_matrix(t_square *map, int t_amount)
{
	int	sq_size;

	if (map != NULL)
	{
		sq_size = map->size + 1;
		free(map);
	}
	else
		sq_size = ft_square_size(t_amount);
	return (ft_create_square(map, sq_size));
}
