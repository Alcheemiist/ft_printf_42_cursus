/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:37:31 by eelaazmi          #+#    #+#             */
/*   Updated: 2019/12/29 23:32:43 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putchar5(char d)
{
	if (g_1etoile != 0 && g_point == 0)
	{
		g_nmbr1 = g_nmbr2;
		g_nmbr2 = 0;
	}
	if (g_minus != 0)
		ft_putchar_fd(d, 1);
	min_width();
	if (g_minus == 0)
		ft_putchar_fd(d, 1);
}

void	traitc(void)
{
	char	d;
	int		r;

	r = 0;
	if (g_1etoile != 0)
	{
		g_1etoile = va_arg(g_ap, int);
		g_nmbr1 = g_1etoile;
		if (g_nmbr1 < 0)
		{
			g_minus = 1;
			g_nmbr1 = -g_nmbr1;
		}
	}
	d = va_arg(g_ap, int);
	if (g_nmbr1 == 0 && g_point == 0)
		ft_putchar_fd(d, 1);
	else
	{
		g_nmbr1 -= 1;
		putchar5(d);
	}
}
