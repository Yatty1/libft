/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:44:52 by syamada           #+#    #+#             */
/*   Updated: 2018/07/30 11:24:12 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*flag_x(char *conv, va_list ap)
{
	char	*str;
	int		len;
	t_flag	flag;

	len = ft_strlen(conv) - 2;
	check_flag(&flag, conv);
	if (conv[len] == '%')
		return (ft_itoa_base(va_arg(ap, int), 16, 0));
	if (is_tflag(conv[len]))
	{
		//need flag converter
			return (NULL);
	}
	else
		str = ft_itoa_base(va_arg(ap, int), 16, 0);
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
			return (flag_x(conv, ap));
		i++;
	}
	return (NULL);
}
