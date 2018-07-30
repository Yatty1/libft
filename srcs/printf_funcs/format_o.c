/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:44:27 by syamada           #+#    #+#             */
/*   Updated: 2018/07/30 11:23:49 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		//need flag converter
			return (NULL);
	}
	else
		str = ft_itoa_base(va_arg(ap, int), 8, 0);
	str = width_prec_fill(flag, str);
	return (str);
}

//base 8
char	*format_o(va_list ap, char *conv)
{
	int		i;

	i = 0;
	while (conv[i])
	{
		if (conv[i] == 'o')
			return (flag_o(conv, ap));
		i++;
	}
	return (NULL);
}
