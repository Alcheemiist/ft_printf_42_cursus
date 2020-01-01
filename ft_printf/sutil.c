/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sutil.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:37:15 by eelaazmi          #+#    #+#             */
/*   Updated: 2019/12/29 20:37:20 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	elseprincipal1(char *d)
{
	if (d == 0)
	{
		g_nmbr1 -= 6;
		g_nmbr2 = 6;
	}
	else
	{
		g_nmbr1 -= ft_strlen(d);
		g_nmbr2 = ft_strlen(d);
	}
}

void	traitements(char *d, int r)
{
	r = (g_nmbr2 < 0) ? 0 : g_nmbr2;
	if (d != 0)
		r = (g_nmbr2 < ft_strlen(d) && g_nmbr2 >= 0) ? g_nmbr2 : ft_strlen(d);
	else
		r = (g_nmbr2 < 6) ? g_nmbr2 : 6;
	if (d == 0 && g_nmbr2 < 0)
	{
		g_nmbr1 -= 6;
		g_nmbr2 = 6;
	}
	else if (g_nmbr2 != 0)
	{
		if (d == 0)
			g_nmbr1 -= r;
		else
			g_nmbr1 -= r;
	}
	else if (g_nmbr2 == 0 && g_point == 0)
		elseprincipal1(d);
	else
		g_nmbr1 -= g_nmbr2;
	putchar6(d, r);
}

int		traitaitements(int r)
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

void	ft_putnbr_fdu(unsigned int n, int fd)
{
	unsigned int	nouvar;

	nouvar = n;
	if (nouvar <= 9)
	{
		ft_putchar_fd(nouvar + 48, fd);
	}
	if (nouvar > 9)
	{
		ft_putnbr_fd(nouvar / 10, fd);
		ft_putchar_fd(nouvar % 10 + 48, fd);
	}
}

int		traitementu(int r)
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
