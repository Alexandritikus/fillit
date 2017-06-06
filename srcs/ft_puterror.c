/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:09:29 by oshudria          #+#    #+#             */
/*   Updated: 2016/12/22 16:28:30 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_puterror(int n)
{
	if (n == 0)
		ft_putendl("malloc error");
	if (n == 1)
		ft_putendl("open file error");
	if (n == 2)
		ft_putendl("error");
	if (n == 3)
	{
		ft_putendl("usage: ./fillit source_file");
		ft_putendl("also you may use color mode: ./fillit source_file --color");
		ft_putendl("color mode does not work with cat -e");
	}
	exit(1);
}
