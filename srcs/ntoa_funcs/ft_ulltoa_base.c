/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 10:07:42 by syamada           #+#    #+#             */
/*   Updated: 2018/08/04 15:11:21 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		conv_ex(int nb, int is_cap)
{
	char c;

	c = is_cap ? 'A' : 'a';
	if (nb >= 10)
		return (nb - 10 + c);
	else
		return (nb + '0');
}

char			*ft_ulltoa_base(unsigned long long num, unsigned int base,
								int is_cap)
{
	int					i;
	char				*str;
	unsigned long long	tmp;

	i = 0;
	tmp = num;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}
	if (!(str = ft_strnew(++i)))
		return (NULL);
	str[i--] = '\0';
	while (i >= 0)
	{
		tmp = num % base;
		str[i] = conv_ex(tmp, is_cap);
		num /= base;
		i--;
	}
	return (str);
}
