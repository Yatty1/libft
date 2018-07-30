/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:43:30 by syamada           #+#    #+#             */
/*   Updated: 2018/07/30 11:23:05 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*flag_i(char *conv, va_list ap)
{
	char	*str;
	int		len;
	t_flag	flag;

	len = ft_strlen(conv) - 2;
	check_flag(&flag, conv);
	if (conv[len] == '%')
		return (ft_itoa(va_arg(ap, int)));
	if (is_tflag(conv[len]))
	{
			return (NULL);
	}
	else
		str = ft_itoa(va_arg(ap, int));
	str = width_prec_fill(flag, str);
	return (str);
}

char		*format_i(va_list ap, char *conv)
{
	int		i;

	i = 0;
	while (conv[i])
	{
		if (conv[i] == 'i')
			return (flag_i(conv, ap));
		i++;
	}
	return (NULL);
}
