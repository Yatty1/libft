/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 18:12:30 by syamada           #+#    #+#             */
/*   Updated: 2018/08/05 17:53:31 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cvt_flag(char *conv, va_list ap, char **str, int len)
{
	char	*flag;

	if (!(flag = take_flag(conv, len)))
		return (-1);
	if (ft_strcmp(flag, "l") == 0)
		*str = ft_wchar(ft_strnew(1), va_arg(ap, wchar_t));
	free(flag);
	if (!*str)
		return (-1);
	return (len);
}

static char	*flag_c(char *conv, va_list ap, char *c_s, int *t_len)
{
	char	*str;
	char	c;
	int		len;
	t_flag	flag;

	len = ft_strlen(conv) - 2;
	check_flag(&flag, conv, ap);
	if (conv[len] == '%')
	{
		c = va_arg(ap, int);
		return (c == 0 ? put_null(c_s, t_len, &flag) : ft_charstr(c));
	}
	if (is_tflag(conv[len]))
	{
		if ((len = cvt_flag(conv, ap, &str, len)) < 0)
			return (ft_strdup(""));
	}
	else
	{
		c = va_arg(ap, int);
		str = c == 0 ? put_null(c_s, t_len, &flag) : ft_charstr(c);
	}
	flag.str = 1;
	str = width_prec_fill(flag, str);
	return (str);
}

static char	*flag_cc(char *conv, va_list ap, char *c_s, int *t_len)
{
	char	*str;
	wchar_t	c;
	int		len;
	t_flag	flag;

	len = ft_strlen(conv) - 2;
	check_flag(&flag, conv, ap);
	if (conv[len] == '%')
	{
		if ((c = va_arg(ap, wchar_t)) == 0)
			return (put_null(c_s, t_len, &flag));
		return (ft_wchar(ft_strnew(1), c));
	}
	c = va_arg(ap, wchar_t);
	str = c == 0 ? put_null(c_s, t_len, &flag) : ft_wchar(ft_strnew(1), c);
	flag.str = 1;
	str = width_prec_fill(flag, str);
	return (str);
}

char		*format_c(va_list ap, char *conv, char *str, int *len)
{
	int		i;

	i = 0;
	while (conv[i])
	{
		if (conv[i] == 'c')
			return (flag_c(conv, ap, str, len));
		if (conv[i] == 'C')
			return (flag_cc(conv, ap, str, len));
		i++;
	}
	return (NULL);
}
