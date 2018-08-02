/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:44:52 by syamada           #+#    #+#             */
/*   Updated: 2018/08/01 23:26:24 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*flag_x(char *conv, va_list ap, int is_cap)
{
	char	*str;
	int		len;
	t_flag	flag;

	len = ft_strlen(conv) - 2;
	check_flag(&flag, conv);
	if (conv[len] == '%')
		return (ft_itoa_base(va_arg(ap, int), 16, is_cap));
	if (is_tflag(conv[len]))
	{
		if ((len = cvt_flag_oux(conv, ap, &str, len)) > 0)
			return (NULL);
	}
	else
		str = ft_itoa_base(va_arg(ap, int), 16, is_cap);
	str = width_prec_fill(flag, str);
	return (str);
}

char	*format_x(va_list ap, char *conv)
{
	int		i;

	i = 0;
	while (conv[i])
	{
		if (conv[i] == 'x')
			return (flag_x(conv, ap, 0));
		if (conv[i] == 'X')
			return (flag_x(conv, ap, 1));
		i++;
	}
	return (NULL);
}
