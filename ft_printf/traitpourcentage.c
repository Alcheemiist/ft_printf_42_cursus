/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitpourcentage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:38:17 by eelaazmi          #+#    #+#             */
/*   Updated: 2019/12/29 20:38:22 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putchar7(void)
{
	if (g_minus != 0 && g_nmbr1 != 0)
	{
		if (g_nmbr1 != 0)
		{
			ft_putchar_fd('%', 1);
			min_width();
		}
	}
	else if (g_minus == 0 && g_nmbr1 != 0)
	{
		if (g_zero != 0)
		{
			g_nmbr2 = g_nmbr1;
			precision();
			ft_putchar_fd('%', 1);
		}
		else
		{
			min_width();
			ft_putchar_fd('%', 1);
		}
	}
	else
		ft_putchar_fd('%', 1);
}

void	traitpourcentage(void)
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
	}
	if (g_nmbr1 == 0 && g_point == 0)
		ft_putchar_fd('%', 1);
	else
	{
		g_nmbr1 -= 1;
		putchar7();
	}
}
