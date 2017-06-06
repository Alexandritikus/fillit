/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:11:27 by oshudria          #+#    #+#             */
/*   Updated: 2016/12/22 16:09:34 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_paste(t_square *m, t_tetramin *tetr, int pos)
{
	m->str[pos] = tetr->letter;
	m->str[pos + (tetr->second)->x * (m->size + 1) +
	(tetr->second)->y] = tetr->letter;
	m->str[pos + (tetr->third)->x * (m->size + 1) +
	(tetr->third)->y] = tetr->letter;
	m->str[pos + (tetr->fourth)->x * (m->size + 1) +
	(tetr->fourth)->y] = tetr->letter;
}

static void	ft_clear(char *tab, char c)
{
	char	*tmp;

	tmp = tab;
	while (*tmp)
	{
		if (*tmp == c || *tmp == '1')
			*tmp = '.';
		tmp++;
	}
}

static int	ft_check_current(int pos, t_square *m, t_tetramin *tetr, int n)
{
	int res;

	res = 0;
	if (m->str[pos] == '.' &&
		m->str[pos + (tetr->second)->x * (m->size + 1) +
		(tetr->second)->y] == '.' &&
		m->str[pos + (tetr->third)->x * (m->size + 1) +
		(tetr->third)->y] == '.' &&
		m->str[pos + (tetr->fourth)->x * (m->size + 1) +
		(tetr->fourth)->y] == '.')
	{
		if (m->size * m->size == n * 4)
		{
			ft_paste(m, tetr, pos);
			res = ft_check_free_space(m);
			ft_clear(m->str, tetr->letter);
		}
		else
			res = 1;
		return (res);
	}
	return (res);
}

static int	find_next_pos(t_square *m, t_tetramin *tetr, int pos_num, int n)
{
	int pos;
	int last_pos;

	pos = -1;
	last_pos = (int)ft_strlen(m->str) - 2;
	while (pos_num > 0 && ++pos <= last_pos)
	{
		while (m->str[pos] != '.' && m->str[pos] != '\0')
			pos++;
		if (m->str[pos] == '\0')
			return (-1);
		if (pos > last_pos || pos + (tetr->fourth)->x * (m->size + 1) +
			(tetr->fourth)->y > last_pos)
			return (-1);
		if (ft_check_current(pos, m, tetr, n) == 0)
			pos_num += 1;
		pos_num -= 1;
	}
	if (ft_check_current(pos, m, tetr, n) == 0)
		return (-1);
	else
		return (pos);
}

int			ft_solve(t_square *map, t_tetramin **t_tab, int i, int n)
{
	int pos;
	int pos_num;

	if (t_tab[i] == NULL)
		return (1);
	pos_num = 1;
	while ((pos = find_next_pos(map, t_tab[i], pos_num, n)) != -1)
	{
		ft_paste(map, t_tab[i], pos);
		if (ft_solve(map, t_tab, i + 1, n) == 1)
			return (1);
		ft_clear(map->str, t_tab[i]->letter);
		pos_num += 1;
	}
	return (0);
}
