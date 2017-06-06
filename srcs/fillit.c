/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:04:12 by oshudria          #+#    #+#             */
/*   Updated: 2016/12/22 15:23:03 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*fillit(char *file_name)
{
	int			t_amount;
	t_tetramin	**t_tab;
	t_square	*map;
	int			tetr_index;

	tetr_index = 0;
	t_amount = 0;
	map = NULL;
	t_tab = ft_read(file_name, &t_amount);
	map = ft_build_matrix(map, t_amount);
	while (ft_solve(map, t_tab, tetr_index, t_amount) == 0)
		map = ft_build_matrix(map, t_amount);
	free(t_tab);
	return (map->str);
}

int			main(int argc, char **argv)
{
	char	*output;
	int		color_mode;

	if (argc == 1 || argc > 3)
		ft_puterror(3);
	if (argc == 2)
		color_mode = 0;
	if (argc == 3)
	{
		color_mode = ft_strequ(argv[2], "--color");
		if (color_mode == 0)
			ft_puterror(3);
	}
	output = fillit(argv[1]);
	ft_output(output, color_mode);
	return (0);
}
