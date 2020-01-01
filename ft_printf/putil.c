/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putil.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:37:01 by eelaazmi          #+#    #+#             */
/*   Updated: 2019/12/29 20:37:05 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		lenthp(size_t nb)
{
	int	i;

	i = 1;
	while ((nb = (nb / 16)) != 0)
	{
		i++;
	}
	return (i + 2);
}

int		traitementp(int r)
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
