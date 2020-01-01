/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:39:22 by eelaazmi          #+#    #+#             */
/*   Updated: 2019/12/29 20:39:40 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dnull1x(void)
{
	if (g_minus != 0)
	{
		ft_putchar_fd('0', 1);
		min_width();
	}
	if (g_minus == 0)
	{
		if (g_zero != 0)
		{
			g_nmbr2 = g_nmbr1;
			precision();
		}
		else
		{
			min_width();
		}
		ft_putchar_fd('0', 1);
	}
}

void	dnull2x(void)
{
	if (g_point == 0)
	{
		if (g_minus == 0)
			min_width();
		ft_putchar_fd('0', 1);
		if (g_minus != 0)
			min_width();
	}
	else
	{
		g_nmbr1 = g_nmbr1 + 1;
		min_width();
	}
}

void	elseprincipalex(unsigned int d, const char *fmt, int i, int r)
{
	if (g_minus != 0)
	{
		precision();
		hexa(d, fmt, i);
		min_width();
	}
	else if (g_zero != 0 && r < 0)
	{
		g_nmbr2 = g_nmbr1;
		precision();
		hexa(d, fmt, i);
	}
	else
	{
		min_width();
		precision();
		hexa(d, fmt, i);
	}
}

void	putchar3(unsigned int d, int r, const char *fmt, int i)
{
	if (g_zero != 0 && g_point == 0)
	{
		g_nmbr2 = g_nmbr1;
		g_nmbr1 = 0;
	}
	if (r < 0 && d == 0 && g_point != 0)
	{
		dnull1x();
	}
	else if (g_nmbr2 == 0 && d == 0 && r == 0)
	{
		dnull2x();
	}
	else
	{
		elseprincipalex(d, fmt, i, r);
	}
}

void	traitx(const char *fmt, int i)
{
	unsigned int	d;
	int				r;

	r = 0;
	r = traitementx(r);
	d = va_arg(g_ap, unsigned int);
	if (g_nmbr2 == 0 && g_nmbr1 == 0 && g_point == 0)
		hexa(d, fmt, i);
	else
	{
		g_nmbr2 -= lenthx(d);
		if (g_nmbr2 < 0)
			g_nmbr2 = 0;
		else
			g_nmbr2 = (g_nmbr2 == 0) ? 0 : g_nmbr2;
		g_nmbr1 -= (g_nmbr2 + lenthx(d));
		putchar3(d, r, fmt, i);
	}
}
