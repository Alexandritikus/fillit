/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_free_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 19:16:11 by oshudria          #+#    #+#             */
/*   Updated: 2016/12/22 16:09:43 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_find_free_space(int step, int pos, t_square *map, int max)
{
	map->str[pos] = '1';
	if (pos - 1 >= 0 && map->str[pos - 1] == '.')
		ft_find_free_space(step + 1, pos - 1, map, max);
	if (pos - map->size - 1 >= 0 && map->str[pos - map->size - 1] == '.')
		ft_find_free_space(step + 1, pos - map->size - 1, map, max);
	if (pos + 1 <= max && map->str[pos + 1] == '.')
		ft_find_free_space(step + 1, pos + 1, map, max);
	if (pos + map->size + 1 <= max && map->str[pos + map->size + 1] == '.')
		ft_find_free_space(step + 1, pos + map->size + 1, map, max);
}

static int	ft_count_space(char *str)
{
	int	n;

	n = 0;
	while (*str != '\0')
	{
		if (*str == '1')
			n += 1;
		str++;
	}
	return (n);
}

int			ft_check_free_space(t_square *map)
{
	int	pos;
	int	last_pos;
	int dash_n;
	int	total_dash;

	pos = -1;
	dash_n = 0;
	total_dash = 0;
	last_pos = (int)ft_strlen(map->str) - 2;
	while (++pos <= last_pos)
	{
		if (map->str[pos] == '.')
		{
			ft_find_free_space(0, pos, map, last_pos);
			dash_n = ft_count_space(map->str) - total_dash;
			if (dash_n % 4 != 0)
				return (0);
			total_dash += dash_n;
		}
	}
	return (1);
}
