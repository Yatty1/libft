/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 22:36:43 by syamada           #+#    #+#             */
/*   Updated: 2018/08/05 16:12:56 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_parser(char *fmt, char **str)
{
	char	*tmp;
	int		i;

	i = 0;
	while (fmt[i] != '%' && fmt[i])
		i++;
	if (!*str)
		*str = ft_strsub(fmt, 0, i);
	else
	{
		tmp = ft_strsub(fmt, 0, i);
		*str = ft_strjoinfree(*str, tmp);
	}
	if (fmt[i] == '\0')
		return (NULL);
	return (fmt + i);
}

char	*format_parser(char *fmt, char **str, va_list ap, int *len)
{
	char	*tmp;
	char	*t;
	int		i;

	i = 0;
	if (fmt[i] == '%')
	{
		i++;
		while (!is_conversion(fmt[i]) && fmt[i])
			i++;
		if (fmt[i] == '\0')
			return (NULL);
		if (!(tmp = ft_strsub(fmt, 0, i + 1)))
			return (NULL);
		if (!*str)
			*str = check_conv(ap, tmp, *str, len);
		else
		{
			if (!(t = check_conv(ap, tmp, *str, len)))
				t = ft_strdup("(null)");
			*str = ft_strjoinfree(*str, t);
		}
		ft_strdel(&tmp);
	}
	return (fmt + i + 1);
}
