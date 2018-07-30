/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:42:58 by syamada           #+#    #+#             */
/*   Updated: 2018/07/30 11:23:38 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cvt_flag_d(char *conv, va_list ap, char **str, int len)
{
	char	*flag;
	int		i;

	i = 0;
	while (!ft_isdigit(conv[len]) && len > 0)
	{
		len--;
		i++;
	}
	flag = ft_strsub(conv, len + 1, i);
	if (ft_strcmp(flag, "hh") == 0)
		*str = ft_itoa(va_arg(ap, int));
	else if (ft_strcmp(flag, "h") == 0)
		*str = ft_itoa(va_arg(ap, int));
	else if (ft_strcmp(flag, "l") == 0)
		*str = ft_itoa(va_arg(ap, long));
	else if (ft_strcmp(flag, "ll") == 0)
		*str = ft_itoa(va_arg(ap, long long));
	else if (ft_strcmp(flag, "j") == 0)
		*str = ft_itoa(va_arg(ap, int));
	else if (ft_strcmp(flag, "z") == 0)
		*str = ft_itoa(va_arg(ap, int));
	free(flag);
	if (!*str)
		return (-1);
	return (len);
}

static char	*flag_d(char *conv, va_list ap)
{
	char	*str;
	int		len;
	t_flag	flag;

	len = ft_strlen(conv) - 2;
	check_flag(&flag, conv);
	if (conv[len] == '%')
		return (ft_itoa(va_arg(ap, int)));
	if (is_tflag(conv[len]))
	{
		if ((len = cvt_flag_d(conv, ap, &str, len)) < 0)
			return (NULL);
	}
	else
		str = ft_itoa(va_arg(ap, int));
	str = width_prec_fill(flag, str);
	return (str);
}

char		*format_d(va_list ap, char *conv)
{
	int		i;
	char	*str;

	i = 0;
	while (conv[i])
	{
		if (conv[i] == 'd')
			return (flag_d(conv, ap));
		else if (conv[i] == 'D')
			str = ft_itoa(va_arg(ap, int));
		i++;
	}
	if (!str)
		return (NULL);
	return (str);
}
