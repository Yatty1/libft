/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:44:40 by syamada           #+#    #+#             */
/*   Updated: 2018/07/30 11:23:26 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*flag_u(char *conv, va_list ap)
{
	char	*str;
	int		len;
	t_flag	flag;

	len = ft_strlen(conv) - 2;
	check_flag(&flag, conv);
	if (conv[len] == '%')
		return (ft_uitoa_base(va_arg(ap, unsigned int), 10, 0));
	if (is_tflag(conv[len]))
	{
			return (NULL);
	}
	else
		str = ft_uitoa_base(va_arg(ap, unsigned int), 10, 0);
	str = width_prec_fill(flag, str);
	return (str);
}

char		*format_u(va_list ap, char *conv)
{
	int		i;
	char	*str;

	i = 0;
	while (conv[i])
	{
		if (conv[i] == 'u')
			return (flag_u(conv, ap));
		else if (conv[i] == 'D')
			str = ft_ultoa_base(va_arg(ap, unsigned long), 10, 0);
		i++;
	}
	if (!str)
		return (NULL);
	return (str);
}
