/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_prec_fill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 22:02:17 by syamada           #+#    #+#             */
/*   Updated: 2018/08/04 18:31:35 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*adjust_precision(char *str, t_flag *flag)
{
	char	*tmp;
	char	*prec;
	int		len;

	len = flag->precision - ft_strlen(str);
	if (len > 0 && (flag->zero || !flag->str))
	{
		prec = (char *)ft_memset(ft_strnew(len), '0', len);
		tmp = ft_strjoin(prec, str);
		free(str);
		free(prec);
		flag->zero_processed = 1;
	}
	else if (len >= 0)
		return (str);
	else if (flag->str)
	{
		tmp = ft_strsub(str, 0, flag->precision);
		free(str);
		flag->zero_processed = 1;
	}
	else if (flag->dot && flag->precision == 0 && *str == '0')
	{
		if (flag->width > 0)
			tmp = (char *)ft_memset(ft_strnew(flag->width), ' ', flag->width);
		else if (flag->hash && flag->octal)
			tmp = ft_strdup(str);
		else
			tmp = ft_strdup("");
		free(str);
	}
	else
		tmp = str;
	return (tmp);
}

char			*fill_width(char *str, t_flag flag)
{
	char	*tmp;
	char	*prec;
	char	c;

	c = flag.zero && !flag.zero_processed ? '0' : ' ';
	prec = (char *)ft_memset(ft_strnew(flag.width), c, flag.width);
	tmp = flag.minus ? ft_strjoin(str, prec) : ft_strjoin(prec, str);
	free(str);
	free(prec);
	return (tmp);
}

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
		str = ft_strprepend(str, '0');
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
