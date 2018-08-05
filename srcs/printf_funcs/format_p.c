/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:42:30 by syamada           #+#    #+#             */
/*   Updated: 2018/08/04 23:22:27 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*flag_p(char *conv, va_list ap)
{
	char	*str;
	char	*tmp;
	int		len;
	t_flag	flag;

	len = ft_strlen(conv) - 2;
	check_flag(&flag, conv, ap);
	str = ft_lltoa_base(va_arg(ap, long long), 16, 0);
	tmp = ft_strjoin("0x", str);
	free(str);
	str = tmp;
	if (conv[len] == '%')
		return (str);
	str = width_prec_fill(flag, str);
	return (str);
}

char		*format_p(va_list ap, char *conv)
{
	int		i;

	i = 0;
	while (conv[i])
	{
		if (conv[i] == 'p')
			return (flag_p(conv, ap));
		i++;
	}
	return (NULL);
}
