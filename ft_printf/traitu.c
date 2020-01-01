/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:45:21 by eelaazmi          #+#    #+#             */
/*   Updated: 2019/12/29 23:35:10 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dnull1u(void)
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

void	dnull2u(void)
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

void	else1u(unsigned int d, int r)
{
	if (g_minus != 0)
	{
		precision();
		ft_putnbr_fdu(d, 1);
		min_width();
	}
	else if (g_zero != 0 && r < 0)
	{
		g_nmbr2 = g_nmbr1;
		precision();
		ft_putnbr_fdu(d, 1);
	}
	else
	{
		min_width();
		precision();
		ft_putnbr_fdu(d, 1);
	}
}

void	putchar2(unsigned int d, int r)
{
	if (g_zero != 0 && g_point == 0)
	{
		g_nmbr2 = g_nmbr1;
		g_nmbr1 = 0;
	}
	if (r < 0 && d == 0 && g_point != 0)
	{
		dnull1u();
	}
	else if (g_nmbr2 == 0 && d == 0 && r == 0)
	{
		dnull2u();
	}
	else
	{
		else1u(d, r);
	}
}

void	traitu(void)
{
	unsigned int	d;
	int				r;

	r = 0;
	r = traitementu(r);
	d = va_arg(g_ap, unsigned int);
	if (g_nmbr2 == 0 && g_nmbr1 == 0 && g_point == 0)
		ft_putnbr_fdu(d, 1);
	else
	{
		g_nmbr2 -= lenth(d);
		if (g_nmbr2 < 0)
			g_nmbr2 = 0;
		else
			g_nmbr2 = (g_nmbr2 == 0) ? 0 : g_nmbr2;
		g_nmbr1 -= (g_nmbr2 + lenth(d));
		putchar2(d, r);
	}
}
