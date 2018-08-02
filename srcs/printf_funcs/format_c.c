/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:45:08 by syamada           #+#    #+#             */
/*   Updated: 2018/08/01 23:25:29 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// maybe pointer to function? so that I only have to pass functions which manipulate va_arg type
static char	*flag_c(char *conv, va_list ap)
{
	char	*str;
	int		len;
	t_flag	flag;

	len = ft_strlen(conv) - 2;
	check_flag(&flag, conv);
	if (conv[len] == '%')
		return (ft_charstr(va_arg(ap, int)));
	if (is_tflag(conv[len]))
	{
		//need flag converter
			return (NULL);
	}
	else
		str = ft_charstr(va_arg(ap, int));
	str = width_prec_fill(flag, str);
	return (str);
}

char		*format_c(va_list ap, char *conv)
{
	int		i;

	i = 0;
	while (conv[i])
	{
		if (conv[i] == 'c')
			return (flag_c(conv, ap));
		if (conv[i] == 'C')
			return (ft_charstr(va_arg(ap, int)));
		i++;
	}
	return (NULL);
}
