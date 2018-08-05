/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 12:46:43 by syamada           #+#    #+#             */
/*   Updated: 2018/08/04 23:23:55 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*flag_percent(char *conv, va_list ap)
{
	char	*str;
	t_flag	flag;

	if (!ap)
		return (NULL);
	check_flag(&flag, conv, ap);
	str = ft_charstr('%');
	str = width_prec_fill(flag, str);
	return (str);
}

char		*format_percent(va_list ap, char *conv)
{
	int		i;

	i = 0;
	while (conv[i])
	{
		if (conv[i] == '%')
			return (flag_percent(conv, ap));
		i++;
	}
	return (NULL);
}
