/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:45:08 by syamada           #+#    #+#             */
/*   Updated: 2018/08/04 16:01:38 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*put_null(char *str, int *len, t_flag *flag)
{
	char	*wd;

	wd = NULL;
	if (!str)
		return (str);
	if (flag->width > 1)
	{
		*len = flag->width - 1;
		wd = ft_memset(ft_strnew(flag->width - 1), ' ', flag->width - 1);
		flag->width = 0;
	}
	*len += ft_strlen(str);
	ft_putstr(str);
	free(str);
	str = ft_strdup("");
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
	if (wd)
		free(wd);
	*len += 1;
	return (str);
}

static char	*flag_c(char *conv, va_list ap, char *c_s, int *t_len)
{
	char	*str;
	char	c;
	int		len;
	t_flag	flag;

	len = ft_strlen(conv) - 2;
	check_flag(&flag, conv);
	if (conv[len] == '%')
	{
		if ((c = va_arg(ap, int)) == 0)
			return (put_null(c_s, t_len, &flag));
		return (ft_charstr(c));
	}
	if (is_tflag(conv[len]))
		return (NULL);
	else
	{
		c = va_arg(ap, int);
		str = c == 0 ? put_null(c_s, t_len, &flag) : ft_charstr(c);
	}
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
			return (ft_charstr(va_arg(ap, int)));
		i++;
	}
	return (NULL);
}
