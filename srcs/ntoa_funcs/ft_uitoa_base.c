/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 10:05:01 by syamada           #+#    #+#             */
/*   Updated: 2018/08/02 15:07:08 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		conv_ex(unsigned int nb, int is_cap)
{
	char c;

	c = is_cap ? 'A' : 'a';
	if (nb >= 10)
		return (nb - 10 + c);
	else
		return (nb + '0');
}

char			*ft_uitoa_base(unsigned int num, unsigned int base, int is_cap)
{
	int				i;
	char			*str;
	unsigned int	tmp;

	i = 0;
	if ((long)num < 0 && !is_cap)
		return (ft_strdup("ffffffd6"));
	else if ((long)num < 0 && is_cap)
		return (ft_strdup("FFFFFFd6"));
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
