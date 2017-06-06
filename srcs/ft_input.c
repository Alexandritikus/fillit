/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:01:26 by oshudria          #+#    #+#             */
/*   Updated: 2016/12/22 16:46:26 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_coord		*create_coord(int x, int y, t_coord *base, int stage)
{
	t_coord	*new;

	new = malloc(sizeof(t_coord));
	if (!new)
		ft_puterror(0);
	if (stage == 0)
	{
		new->x = x;
		new->y = y;
	}
	else
	{
		new->x = x - base->x;
		new->y = y - base->y;
	}
	return (new);
}

static t_tetramin	*crea_tetr(char *str, char l)
{
	t_tetramin	*new;
	int			i;
	int			dash_count;

	if ((new = malloc(sizeof(t_tetramin))) == NULL)
		ft_puterror(0);
	i = -1;
	dash_count = 0;
	new->letter = l;
	while (str[++i])
	{
		if (str[i] == '#')
		{
			dash_count++;
			if (dash_count == 1)
				new->first = create_coord(i / 5, i % 5, new->first, 0);
			if (dash_count == 2)
				new->second = create_coord(i / 5, i % 5, new->first, 1);
			else if (dash_count == 3)
				new->third = create_coord(i / 5, i % 5, new->first, 1);
			else if (dash_count == 4)
				new->fourth = create_coord(i / 5, i % 5, new->first, 1);
		}
	}
	return (new);
}

t_tetramin			**ft_read(char *file, int *t_counter)
{
	char		*buf;
	int			fd;
	int			ret;
	t_tetramin	**tetra_list;
	int			last_len;

	if ((buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1))) == 0)
		ft_puterror(0);
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_puterror(1);
	if ((tetra_list = (t_tetramin**)malloc(sizeof(t_tetramin) * T_MAX)) == NULL)
		ft_puterror(0);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		t_check(buf, &t_counter);
		tetra_list[*t_counter - 1] = crea_tetr(buf, 'A' + *t_counter - 1);
		last_len = ret;
	}
	if (last_len != 20)
		ft_puterror(2);
	return (tetra_list);
}
