/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:41:22 by syamada           #+#    #+#             */
/*   Updated: 2018/08/05 17:49:09 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cvt_flag(char *conv, va_list ap, char **str, int len)
{
	char	*flag;

	if (!(flag = take_flag(conv, len)))
		return (-1);
	if (ft_strcmp(flag, "l") == 0)
		*str = ft_strwchar(va_arg(ap, wchar_t *));
	free(flag);
	if (!*str)
		return (-1);
	return (len);
}

static char	*flag_cs(char *conv, va_list ap)
{
	char	*str;
	int		len;
	t_flag	flag;

	len = ft_strlen(conv) - 2;
	check_flag(&flag, conv, ap);
	if (!(str = ft_strwchar(va_arg(ap, wchar_t *))))
		return (NULL);
	if (conv[len] == '%')
		return (str);
	flag.str = 1;
	str = width_prec_fill(flag, str);
	return (str);
}

static char	*flag_s(char *conv, va_list ap)
{
	char	*str;
	int		len;
	t_flag	flag;

	len = ft_strlen(conv) - 2;
	check_flag(&flag, conv, ap);
	if (conv[len] == '%')
	{
		if (!(str = va_arg(ap, char *)))
			return (NULL);
		return (ft_strdup(str));
	}
	if (is_tflag(conv[len]))
	{
		if ((len = cvt_flag(conv, ap, &str, len)) < 0)
			return (NULL);
	}
	else
	{
		if (!(str = ft_strdup(va_arg(ap, char *))))
			return (NULL);
	}
	flag.str = 1;
	str = width_prec_fill(flag, str);
	return (str);
}

char		*format_s(va_list ap, char *conv)
{
	int		i;

	i = 0;
	while (conv[i])
	{
		if (conv[i] == 's')
			return (flag_s(conv, ap));
		if (conv[i] == 'S')
			return (flag_cs(conv, ap));
		i++;
	}
	return (NULL);
}
