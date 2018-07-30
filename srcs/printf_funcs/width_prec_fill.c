/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_prec_fill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 22:02:17 by syamada           #+#    #+#             */
/*   Updated: 2018/07/30 11:03:00 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*adjust_precision(char *str, t_flag *flag)
{
	char	*tmp;
	char	*prec;
	int		len;

	len = flag->precision - ft_strlen(str);
	if ((len > 0 && flag->zero) || flag->base)
	{
		prec = (char *)ft_memset(ft_strnew(len), '0', len);
		tmp = ft_strjoin(prec, str);
		free(str);
		free(prec);
		flag->zero_processed = 1;
	}
	else if (len >= 0)
		return (str);
	else
	{
		tmp = ft_strsub(str, 0, flag->precision);
		free(str);
		flag->zero_processed = 1;
	}
	return (tmp);
}

static	char	*fill_width(char *str, t_flag flag)
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
	if (flag.plus && !flag.zero)
		str = ft_strprepend(str, '+');
	if (flag.hash && !flag.zero)
		str = ft_strjoin("0x", str);// memory leak
	if (flag.blank && !flag.zero)
		str = ft_strprepend(str, ' ');
	return (str);
}

char			*width_prec_fill(t_flag flag, char *str)
{
	if (!flag.zero)
		str = preset_prefix(flag, str);
	if (flag.dot)
		str = adjust_precision(str, &flag);
	if ((flag.width -= ft_strlen(str)) > 0)
  		str = fill_width(str, flag);
	if (flag.blank && flag.zero)
		*str = ' ';
	if (flag.plus && flag.zero)
		*str = '+';
	if (flag.hash && flag.zero)
		str[1] = 'x';
	return (str);
}
