/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:37:48 by eelaazmi          #+#    #+#             */
/*   Updated: 2019/12/29 20:44:53 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dnull1(void)
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

void	dnull2(void)
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

void	else1(int d, int r)
{
	d = -d;
	if (g_minus != 0)
	{
		ft_putchar_fd('-', 1);
		precision();
		ft_putnbr_fd(d, 1);
		min_width();
	}
	else if (g_zero != 0 && r < 0)
	{
		g_nmbr2 = g_nmbr1;
		ft_putchar_fd('-', 1);
		precision();
		ft_putnbr_fd(d, 1);
	}
	else
	{
		min_width();
		ft_putchar_fd('-', 1);
		precision();
		ft_putnbr_fd(d, 1);
	}
}

void	else2(int d, int r)
{
	if (g_minus != 0)
	{
		if (g_1etoile != 0 && g_point == 0)
		{
			g_nmbr1 = g_nmbr2;
			g_nmbr2 = 0;
		}
		precision();
		ft_putnbr_fd(d, 1);
		min_width();
	}
	else if (g_zero != 0 && r < 0)
	{
		g_nmbr2 = g_nmbr1;
		precision();
		ft_putnbr_fd(d, 1);
	}
	else
	{
		min_width();
		precision();
		ft_putnbr_fd(d, 1);
	}
}

void	putchar1(int d, int r)
{
	if (g_zero != 0 && g_point == 0)
	{
		g_nmbr2 = g_nmbr1;
		g_nmbr1 = 0;
	}
	if (r < 0 && d == 0 && g_point != 0)
	{
		dnull1();
	}
	else if (g_nmbr2 == 0 && d == 0 && r == 0)
	{
		dnull2();
	}
	else
	{
		if (d < 0)
			else1(d, r);
		if (d >= 0)
			else2(d, r);
	}
}
