/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 17:03:54 by syamada           #+#    #+#             */
/*   Updated: 2018/08/02 15:32:24 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		conv_ex(long long nb, int is_cap)
{
	char c;

	c = is_cap ? 'A' : 'a';
	if (nb >= 10)
		return (nb - 10 + c);
	else
		return (nb + '0');
}

char			*ft_lltoa_base(long long num, int base, int is_cap)
{
	int			i;
	char		*str;
	long long	tmp;

	i = 0;
	tmp = num;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = num % base;
		str[i] = conv_ex(tmp, is_cap);
		num /= base;
		i--;
	}
	return (str);
}
