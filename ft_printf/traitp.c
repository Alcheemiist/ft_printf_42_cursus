/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:38:03 by eelaazmi          #+#    #+#             */
/*   Updated: 2019/12/29 20:38:07 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dnullp(void)
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
			min_width();
		ft_putchar_fd('0', 1);
	}
}

void	else1p(void)
{
	if (g_point == 0)
	{
		if (g_minus == 0)
			min_width();
		ft_putstr_fd("0x0", 1);
		if (g_minus != 0)
			min_width();
	}
	else
	{
		g_nmbr1 = g_nmbr1 + 1;
		if (g_minus == 0)
			min_width();
		ft_putstr_fd("0x", 1);
		if (g_minus != 0)
			min_width();
	}
}

void	else2p(void *d, int r)
{
	if (g_minus != 0)
	{
		if (g_1etoile != 0 && g_point == 0)
		{
			g_nmbr1 = g_nmbr2;
			g_nmbr2 = 0;
		}
		precision();
		pointer(d);
		min_width();
	}
	else if (g_zero != 0 && r < 0)
	{
		g_nmbr2 = g_nmbr1;
		precision();
		pointer(d);
	}
	else
	{
		min_width();
		precision();
		pointer(d);
	}
}

void	putchar4(void *d, int r)
{
	if (g_zero != 0 && g_point == 0)
	{
		g_nmbr2 = g_nmbr1;
		g_nmbr1 = 0;
	}
	if (r < 0 && d == 0 && g_point != 0)
	{
		dnullp();
	}
	else if (g_nmbr2 == 0 && d == 0 && r == 0)
		else1p();
	else
		else2p(d, r);
}

void	traitp(void)
{
	void	*d;
	int		r;

	r = 0;
	r = traitementp(r);
	d = va_arg(g_ap, void*);
	if (g_nmbr2 == 0 && g_nmbr1 == 0 && g_point == 0)
		pointer(d);
	else
	{
		g_nmbr2 -= lenthp((size_t)d);
		if (g_nmbr2 < 0)
			g_nmbr2 = 0;
		else
			g_nmbr2 = (g_nmbr2 == 0) ? 0 : g_nmbr2;
		g_nmbr1 -= (g_nmbr2 + lenthp((size_t)d));
		putchar4(d, r);
	}
}
