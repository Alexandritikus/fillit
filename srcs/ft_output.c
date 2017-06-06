/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 19:10:25 by oshudria          #+#    #+#             */
/*   Updated: 2016/12/22 14:15:57 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_output_one(char c)
{
	if (c == 'A')
		ft_putstr(A_COLOR);
	if (c == 'B')
		ft_putstr(B_COLOR);
	if (c == 'C')
		ft_putstr(C_COLOR);
	if (c == 'D')
		ft_putstr(D_COLOR);
	if (c == 'E')
		ft_putstr(E_COLOR);
	if (c == 'F')
		ft_putstr(F_COLOR);
	if (c == 'G')
		ft_putstr(G_COLOR);
	if (c == 'H')
		ft_putstr(H_COLOR);
	if (c == 'I')
		ft_putstr(I_COLOR);
	ft_putchar(c);
	ft_putstr(DEFAULT);
}

static void	ft_output_two(char c)
{
	if (c == 'J')
		ft_putstr(J_COLOR);
	if (c == 'K')
		ft_putstr(K_COLOR);
	if (c == 'L')
		ft_putstr(L_COLOR);
	if (c == 'M')
		ft_putstr(M_COLOR);
	if (c == 'N')
		ft_putstr(N_COLOR);
	if (c == 'O')
		ft_putstr(O_COLOR);
	if (c == 'P')
		ft_putstr(P_COLOR);
	if (c == 'Q')
		ft_putstr(Q_COLOR);
	if (c == 'R')
		ft_putstr(R_COLOR);
	ft_putchar(c);
	ft_putstr(DEFAULT);
}

static void	ft_output_three(char c)
{
	if (c == 'S')
		ft_putstr(S_COLOR);
	if (c == 'T')
		ft_putstr(T_COLOR);
	if (c == 'U')
		ft_putstr(U_COLOR);
	if (c == 'V')
		ft_putstr(V_COLOR);
	if (c == 'W')
		ft_putstr(W_COLOR);
	if (c == 'X')
		ft_putstr(X_COLOR);
	if (c == 'Y')
		ft_putstr(Y_COLOR);
	if (c == 'Z')
		ft_putstr(Z_COLOR);
	ft_putchar(c);
	ft_putstr(DEFAULT);
}

void		ft_output(char *str, int color_mode)
{
	int i;

	i = 0;
	if (color_mode == 0)
		ft_putstr(str);
	else
	{
		while (str[i] != 0)
		{
			if (str[i] >= 'A' && str[i] <= 'I')
				ft_output_one(str[i]);
			else if (str[i] > 'I' && str[i] <= 'R')
				ft_output_two(str[i]);
			else if (str[i] > 'R' && str[i] <= 'Z')
				ft_output_three(str[i]);
			else
				ft_putchar(str[i]);
			i++;
		}
	}
}
