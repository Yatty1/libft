/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:42:30 by syamada           #+#    #+#             */
/*   Updated: 2018/07/30 11:23:17 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
static char	*width_prec_fill_p(t_flag flag, char *str)
{
	char *tmp;

	if (!flag.dot)
	{
		tmp = ft_strjoin("0x", str);
		free(str);
		str = tmp;
	}
	if ((flag.width -= ft_strlen(str)) > 0)
	//	str = fill_width_p(str, flag);
	if (flag.zero)
		str[1] = 'x';
	if (flag.dot)
	{
		tmp = ft_strjoin("0x", str);
		free(str);
		str = tmp;
	}
	return (str);
}
*/

static char	*flag_p(char *conv, va_list ap)
{
	char	*str;
	int		len;
	t_flag	flag;

	len = ft_strlen(conv) - 2;
	check_flag(&flag, conv);
	if (conv[len] == '%')
		return (ft_lltoa_base(va_arg(ap, long long), 16, 0));
	if (is_tflag(conv[len]))
	{
			return (NULL);
	}
	else
		str = ft_lltoa_base(va_arg(ap, long long), 16, 0);
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
