/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dutils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:33:40 by eelaazmi          #+#    #+#             */
/*   Updated: 2019/12/29 20:33:50 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		traitementd(int r)
{
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
	if (g_2etoile != 0)
	{
		g_2etoile = va_arg(g_ap, int);
		g_nmbr2 = g_2etoile;
		r = g_nmbr2;
	}
	return (r);
}

int		lenth(long nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		nb = -nb;
		while ((nb = (nb / 10)) != 0)
		{
			i++;
		}
		i = i + 1;
	}
	else
	{
		while ((nb = (nb / 10)) != 0)
		{
			i++;
		}
	}
	return (i);
}

void	principalelse(int d, int r)
{
	g_nmbr2 -= lenth(d);
	if (g_nmbr2 < 0)
		g_nmbr2 = 0;
	if (d < 0)
		g_nmbr2 = (g_nmbr2 == 0) ? 0 : g_nmbr2 + 1;
	else
		g_nmbr2 = (g_nmbr2 == 0) ? 0 : g_nmbr2;
	g_nmbr1 -= (g_nmbr2 + lenth(d));
	putchar1(d, r);
}

void	traitd(void)
{
	int	d;
	int	r;

	r = 0;
	r = traitementd(r);
	d = va_arg(g_ap, int);
	if (g_nmbr2 == 0 && g_nmbr1 == 0 && g_point == 0)
	{
		if (d < 0)
			ft_putchar_fd('-', 1);
		ft_putnbr_fd(d, 1);
	}
	else
		principalelse(d, r);
}
