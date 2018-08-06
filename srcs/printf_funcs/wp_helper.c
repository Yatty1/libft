/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wp_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 15:26:31 by syamada           #+#    #+#             */
/*   Updated: 2018/08/05 22:04:39 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*zero_precision(char *str, t_flag flag)
{
	char	*tmp;

	if (flag.width > 0)
		tmp = (char *)ft_memset(ft_strnew(flag.width), ' ', flag.width);
	else if (flag.hash && flag.octal)
		tmp = ft_strdup(str);
	else
		tmp = ft_strdup("");
	free(str);
	return (tmp);
}

char			*adjust_precision(char *str, t_flag *flag)
{
	char	*tmp;
	char	*prec;
	int		len;

	len = flag->precision - ft_strlen(str);
	if (len > 0 && (flag->zero || !flag->str))
	{
		prec = (char *)ft_memset(ft_strnew(len), '0', len);
		tmp = ft_strjoinfree(prec, str);
	}
	else if (len >= 0 || flag->precision < 0)
	{
		flag->zero_processed = 1;
		return (str);
	}
	else if (flag->str)
		tmp = ft_strsubfree(str, 0, flag->precision);
	else if (flag->dot && flag->precision == 0 && *str == '0')
		tmp = zero_precision(str, *flag);
	else
		tmp = str;
	flag->zero_processed = 1;
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
