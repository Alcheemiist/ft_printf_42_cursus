/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xutil.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:39:59 by eelaazmi          #+#    #+#             */
/*   Updated: 2019/12/29 20:40:07 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		traitementx(int r)
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

int		lenthx(long nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		nb = -nb;
		while ((nb = (nb / 16)) != 0)
		{
			i++;
		}
		i = i + 1;
	}
	else
	{
		while ((nb = (nb / 16)) != 0)
		{
			i++;
		}
	}
	return (i);
}

void	hexa(unsigned int n, const char *fmt, int i)
{
	if (n / 16)
		hexa(n / 16, fmt, i);
	if ((n % 16) >= 10 && fmt[i] == 'x')
		ft_putchar_fd((n % 16) + 'a' - 10, 1);
	else if ((n % 16) >= 10 && fmt[i] == 'X')
		ft_putchar_fd((n % 16) + 'A' - 10, 1);
	else
		ft_putchar_fd((n % 16) + '0', 1);
}
