/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:44:27 by syamada           #+#    #+#             */
/*   Updated: 2018/08/01 23:25:49 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static char		*preset_prefix(t_flag flag, char *str)
{
	char	*tmp;

	if (flag.plus && !flag.zero && !flag.negative)
		str = ft_strprepend(str, '+');
	if (flag.hash && !flag.zero && !flag.dot)//since there is already zero
		str = ft_strprepend(str, '0');
	if (flag.blank && !flag.zero)
		str = ft_strprepend(str, ' ');
	return (str);
}

static char		*set_prefix(t_flag flag, char *str)
{
	if (flag.blank && flag.zero)
		*str = ' ';
	if (flag.plus && flag.zero && !flag.negative)
		*str = '+';
	//if (flag.hash && flag.zero)
	//	str[1] = 'x';
	if (flag.negative && flag.zero)
		*str = '-';
	if (flag.negative && flag.dot)
		str = ft_strprepend(str, '-');
	return (str);
}


static char	*width_prec_fill_o(t_flag flag, char *str)
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
*/

static char	*flag_o(char *conv, va_list ap)
{
	char	*str;
	int		len;
	t_flag	flag;

	len = ft_strlen(conv) - 2;
	check_flag(&flag, conv);
	if (conv[len] == '%')
		return (ft_itoa_base(va_arg(ap, int), 8, 0));
	if (is_tflag(conv[len]))
	{
		if ((len = cvt_flag_oux(conv, ap, &str, len)) > 0)
			return (NULL);
	}
	else
		str = ft_itoa_base(va_arg(ap, int), 8, 0);
	flag.octal = 1;
	str = width_prec_fill(flag, str);
	return (str);
}

char	*format_o(va_list ap, char *conv)
{
	int		i;

	i = 0;
	while (conv[i])
	{
		if (conv[i] == 'o')
			return (flag_o(conv, ap));
		if (conv[i] == 'O')
			return (ft_itoa_base(va_arg(ap, int), 8, 0));
		i++;
	}
	return (NULL);
}
