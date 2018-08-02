/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:41:22 by syamada           #+#    #+#             */
/*   Updated: 2018/08/01 23:26:06 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*flag_s(char *conv, va_list ap)
{
	char	*str;
	int		len;
	t_flag	flag;

	len = ft_strlen(conv) - 2;
	check_flag(&flag, conv);
	if (conv[len] == '%')
		return (ft_strdup(va_arg(ap, char *)));
	if (is_tflag(conv[len]))
	{
		//need flag converter
			return (NULL);
	}
	else
		str = ft_strdup(va_arg(ap, char *));
	flag.str = 1;
	str = width_prec_fill(flag, str);
	return (str);
}

char	*format_s(va_list ap, char *conv)
{
	int		i;

	i = 0;
	while (conv[i])
	{
		if (conv[i] == 's')
			return (flag_s(conv, ap));
		if (conv[i] == 'S')
			return (va_arg(ap, char *));
		i++;
	}
	return (NULL);
}
