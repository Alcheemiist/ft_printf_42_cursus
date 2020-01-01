/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:38:31 by eelaazmi          #+#    #+#             */
/*   Updated: 2019/12/29 23:35:41 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	else2s(char *d, int r, char *l)
{
	min_width();
	if (d == 0)
	{
		if (g_nmbr2 < 0)
			g_nmbr2 = 6;
		while (g_nmbr2 > 0 && r < 6)
		{
			ft_putchar_fd(l[r], 1);
			g_nmbr2--;
			r++;
		}
	}
	else
	{
		if (g_nmbr2 < 0)
			g_nmbr2 = ft_strlen(d);
		while (g_nmbr2 > 0 && r < ft_strlen(d))
		{
			ft_putchar_fd(d[r], 1);
			g_nmbr2--;
			r++;
		}
	}
	free(l);
}

void	else1s(char *d, int r, char *l)
{
	if (d == 0)
	{
		if (g_nmbr2 < 0)
			g_nmbr2 = 6;
		while (g_nmbr2 > 0 && r < 6)
		{
			ft_putchar_fd(l[r], 1);
			g_nmbr2--;
			r++;
		}
	}
	else
	{
		if (g_nmbr2 < 0)
			g_nmbr2 = ft_strlen(d);
		while (g_nmbr2 > 0 && r < ft_strlen(d))
		{
			ft_putchar_fd(d[r], 1);
			g_nmbr2--;
			r++;
		}
	}
	min_width();
	free(l);
}

void	putchar6(char *d, int r)
{
	char	*l;

	r = 0;
	l = (d == 0) ? ft_strdup("(null)") : ft_strdup("\0");
	if (g_nmbr2 < 0 && d == 0 && g_point != 0)
	{
		if (g_minus != 0)
		{
			ft_putstr_fd("(null)", 1);
			min_width();
		}
		if (g_minus == 0)
		{
			min_width();
			ft_putstr_fd("(null)", 1);
		}
	}
	if (g_nmbr2 == 0 && g_point != 0)
		min_width();
	else
		(g_minus != 0) ? else1s(d, r, l) : else2s(d, r, l);
}

void	traits(void)
{
	char	*d;
	int		r;

	r = 0;
	r = traitaitements(r);
	d = va_arg(g_ap, char*);
	if (g_nmbr2 == 0 && g_nmbr1 == 0 && g_point == 0)
		(d == 0) ? ft_putstr_fd("(null)", 1) : ft_putstr_fd(d, 1);
	else
	{
		traitements(d, r);
	}
}
