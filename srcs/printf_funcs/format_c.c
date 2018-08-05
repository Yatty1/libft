/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 18:12:30 by syamada           #+#    #+#             */
/*   Updated: 2018/08/05 14:40:59 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	null_helper(t_flag *flag, int *len)
{
	char	*wd;

	wd = NULL;
	if (flag->width > 1)
	{
		*len = flag->width - 1;
		wd = ft_memset(ft_strnew(flag->width - 1), ' ', flag->width - 1);
		flag->width = 0;
	}
	if (flag->minus && wd)
	{
		ft_putchar('\0');
		ft_putstr(wd);
	}
	else if (wd)
	{
		ft_putstr(wd);
		ft_putchar('\0');
	}
	else
		ft_putchar('\0');
	if (wd != NULL)
		free(wd);
}

static char	*put_null(char *str, int *len, t_flag *flag)
{
	if (!str)
		return (ft_strdup(""));
	*len += ft_strlen(str);
	ft_putstr(str);
	free(str);
	str = NULL;
	str = ft_strdup("");
	null_helper(flag, len);
	*len += 1;
	return (ft_strdup(""));
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
