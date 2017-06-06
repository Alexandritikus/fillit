/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:26:18 by oshudria          #+#    #+#             */
/*   Updated: 2016/12/16 14:21:50 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_neighbor(char *str, int pos, int *nb_count, int *dash_count)
{
	*dash_count = *dash_count + 1;
	if (pos == 0)
		*nb_count += (str[pos + 1] == '#') + (str[pos + 5] == '#');
	else if (pos == 18)
		*nb_count += (str[pos - 1] == '#') + (str[pos - 5] == '#');
	else if (pos >= 1 && pos <= 3)
		*nb_count += (str[pos + 1] == '#') + (str[pos + 5] == '#') +
			(str[pos - 1] == '#');
	else if (pos >= 15 && pos <= 17)
		*nb_count += (str[pos + 1] == '#') + (str[pos - 5] == '#') +
			(str[pos - 1] == '#');
	else
		*nb_count += (str[pos + 1] == '#') + (str[pos - 1] == '#') +
			(str[pos + 5] == '#') + (str[pos - 5] == '#');
}

static int	ft_lstrlen(const char *str, int pos)
{
	int	i;

	i = pos;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i - pos);
}

void		t_check(char *str, int **counter)
{
	int	i;
	int	dash_count;
	int	nb_count;

	i = 0;
	nb_count = 0;
	dash_count = 0;
	**counter = **counter + 1;
	if (**counter > 26)
		ft_puterror(2);
	while (str[i] != '\0')
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			ft_puterror(2);
		if ((i == 0 || i == 5 || i == 10 || i == 15) &&
			(ft_lstrlen(str, i) != 4))
			ft_puterror(2);
		if (str[i] == '#')
			ft_neighbor(str, i, &nb_count, &dash_count);
		i++;
	}
	if (i < 20 || dash_count != 4 || (nb_count != 6 && nb_count != 8))
		ft_puterror(2);
	if (i == 21 && str[i - 1] != '\n')
		ft_puterror(2);
}
