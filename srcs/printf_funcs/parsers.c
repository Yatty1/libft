/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 22:36:43 by syamada           #+#    #+#             */
/*   Updated: 2018/08/01 23:20:47 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_parser(char *fmt, char **str)
{
	char	*tmp;
	char	*buf;
	int		i;

	i = 0;
	while (fmt[i] != '%' && fmt[i])
		i++;
	if (!*str)
		*str = ft_strsub(fmt, 0, i);
	else
	{
		tmp = ft_strsub(fmt, 0, i);
		buf = ft_strjoin(*str, tmp);
		free(tmp);
		free(*str);
		*str = buf;
	}
	if (fmt[i] == '\0')
		return (NULL);
	return (fmt + i);
}

char	*format_parser(char *fmt, char **str, va_list ap)
{
	char	*buf;
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
		tmp = ft_strsub(fmt, 0, i + 1);
		if (!*str)
			*str = check_conv(ap, tmp);
		else
		{
			t = check_conv(ap, tmp);
			buf = ft_strjoin(*str, t);
			free(t);
			free(*str);
			*str = buf;
		}
		free(tmp);
	}
	return (fmt + i + 1);
}
