/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:34:55 by eelaazmi          #+#    #+#             */
/*   Updated: 2019/12/29 20:34:59 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int		g_pourcentage2;
int		g_minus;
int		g_1etoile;
int		g_2etoile;
int		g_point;
int		g_nmbr1;
int		g_nmbr2;
int		g_count;
int		g_zero;
va_list	g_ap;
int		g_moin;

int		ft_printf(const char *fmt, ...);
void	global(void);
int		traitementdesflags(const char *fmt, int i);
int		passdigits(const char *fmt, int i);
int		ft_isdigit(int c);
void	traitformats(const char *fmt, int i);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	traitd(void);
void	traitu(void);
void	min_width(void);
void	precision(void);
int		lenth(long nb);
void	traitx(const char *fmt, int i);
void	traitp();
void	traitc();
void	traits();
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *s);
void	traitpourcentage();
int		passminus(const char *fmt, int i);
void	putchar1(int d, int r);
void	pointer(void *n);
int		traitementd(int r);
void	principalelse(int d, int r);
int		traitementp(int r);
int		lenthp(size_t nb);
void	hexa(unsigned int n, const char *fmt, int i);
int		lenthx(long nb);
int		traitementx(int r);
void	elseprincipal1(char *d);
void	traitements(char *d, int r);
int		traitaitements(int r);
void	putchar6(char *d, int r);
void	ft_putnbr_fdu(unsigned int n, int fd);
int		traitementu(int r);

#endif
