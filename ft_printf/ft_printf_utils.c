/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:35:09 by eelaazmi          #+#    #+#             */
/*   Updated: 2019/12/29 20:35:13 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hexg_apointer(size_t n)
{
	if (n / 16)
		hexg_apointer(n / 16);
	if ((n % 16) >= 10)
		ft_putchar_fd((n % 16) + 'a' - 10, 1);
	else
		ft_putchar_fd((n % 16) + '0', 1);
}

void	pointer(void *n)
{
	ft_putstr_fd("0x", 1);
	hexg_apointer((size_t)n);
}

void	min_width(void)
{
	while (g_nmbr1 > 0)
	{
		ft_putchar_fd(' ', 1);
		g_nmbr1--;
	}
}

void	precision(void)
{
	while (g_nmbr2 > 0)
	{
		ft_putchar_fd('0', 1);
		g_nmbr2--;
	}
}

int		passminus(const char *fmt, int i)
{
	if (fmt[i] == '-')
	{
		while (fmt[i] == '-')
			i++;
	}
	return (i);
}
