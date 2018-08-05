/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_prec_fill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 22:02:17 by syamada           #+#    #+#             */
/*   Updated: 2018/08/05 15:30:58 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*preset_prefix(t_flag flag, char *str)
{
	char	*tmp;

	if (flag.plus && !flag.zero && !flag.negative && flag.is_signed)
		str = ft_strprepend(str, '+');
	if (flag.hash && !flag.zero && !flag.octal)
	{
		tmp = ft_strjoin(flag.is_cap ? "0X" : "0x", str);
		free(str);
		str = tmp;
	}
	else if (flag.hash && !flag.zero && !flag.dot && flag.octal)
	{
		if (*str != '0')
			str = ft_strprepend(str, '0');
	}
	else if (flag.blank && !flag.zero && flag.is_signed)
		str = ft_strprepend(str, ' ');
	return (str);
}

static char		*set_prefix(t_flag flag, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (flag.blank && flag.zero && flag.is_signed)
		*str = ' ';
	if (flag.plus && flag.zero && !flag.negative && flag.is_signed)
		*str = '+';
	if (flag.hash && flag.zero && !flag.octal)
		str[1] = flag.is_cap ? 'X' : 'x';
	if (flag.negative && flag.zero && flag.width > 0)
		*str = '-';
	else if (flag.negative && flag.zero && flag.width < len)
		str = ft_strprepend(str, '-');
	else if (flag.negative && flag.dot)
		str = ft_strprepend(str, '-');
	return (str);
}

/*
** this fill func is for s,d,i,c,u,x,o
*/

char			*width_prec_fill(t_flag flag, char *str)
{
	if (flag.dot)
		str = adjust_precision(str, &flag);
	if (!flag.zero)
		str = preset_prefix(flag, str);
	if ((flag.width -= ft_strlen(str)) > 0)
		str = fill_width(str, flag);
	str = set_prefix(flag, str);
	return (str);
}
