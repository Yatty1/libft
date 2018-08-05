/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:44:52 by syamada           #+#    #+#             */
/*   Updated: 2018/08/04 23:24:29 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cvt_flag_x(char *conv, va_list ap, char **str, int len)
{
	char	*flag;

	if (!(flag = take_flag(conv, len)))
		return (-1);
	if (ft_strcmp(flag, "hh") == 0)
		*str = ft_uitoa_base((unsigned char)va_arg(ap, unsigned int), 16, 0);
	else if (ft_strcmp(flag, "h") == 0)
		*str = ft_uitoa_base((unsigned short)va_arg(ap, unsigned int), 16, 0);
	else if (ft_strcmp(flag, "l") == 0)
		*str = ft_ultoa_base(va_arg(ap, unsigned long), 16, 0);
	else if (ft_strcmp(flag, "ll") == 0)
		*str = ft_ulltoa_base(va_arg(ap, unsigned long long), 16, 0);
	else if (ft_strcmp(flag, "j") == 0)
		*str = ft_uimaxtoa_base(va_arg(ap, uintmax_t), 16, 0);
	else if (ft_strcmp(flag, "z") == 0)
		*str = ft_sizetoa_base(va_arg(ap, size_t), 16, 0);
	free(flag);
	if (!*str)
		return (-1);
	return (len);
}

static char	*flag_x(char *conv, va_list ap, int is_cap)
{
	char		*str;
	int			len;
	t_flag		flag;

	len = ft_strlen(conv) - 2;
	check_flag(&flag, conv, ap);
	if (conv[len] == '%')
		return (ft_uitoa_base(va_arg(ap, unsigned int), 16, is_cap));
	if (is_tflag(conv[len]))
	{
		if ((len = cvt_flag_x(conv, ap, &str, len)) < 0)
			return (NULL);
	}
	else
		str = ft_uitoa_base(va_arg(ap, int), 16, is_cap);
	if (*str == '0')
		flag.hash = 0;
	flag.is_cap = is_cap;
	str = width_prec_fill(flag, str);
	return (str);
}

char		*format_x(va_list ap, char *conv)
{
	int		i;

	i = 0;
	while (conv[i])
	{
		if (conv[i] == 'x')
			return (flag_x(conv, ap, 0));
		if (conv[i] == 'X')
			return (flag_x(conv, ap, 1));
		i++;
	}
	return (NULL);
}
