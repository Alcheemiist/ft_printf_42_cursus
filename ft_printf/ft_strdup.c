/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:36:28 by eelaazmi          #+#    #+#             */
/*   Updated: 2019/12/29 20:36:36 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcpy1(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		n;
	char	*dest;

	i = 0;
	n = 0;
	while (s1[i] != '\0')
	{
		i++;
		n++;
	}
	n++;
	if (!(dest = malloc(n * sizeof(char))))
		return (0);
	ft_strcpy1(dest, s1);
	return (dest);
}
