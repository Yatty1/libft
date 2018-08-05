/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:43:30 by syamada           #+#    #+#             */
/*   Updated: 2018/08/04 23:21:51 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*take_minus(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*n_str;

	len = ft_strlen(str);
	n_str = (char *)malloc(sizeof(char) * len);
	i = 0;
	j = 1;
	while (ft_isdigit(str[j]))
		n_str[i++] = str[j++];
	n_str[i] = '\0';
	free(str);
	return (n_str);
}

static char	*flag_i(char *conv, va_list ap)
{
	char	*str;
	int		len;
	t_flag	flag;

	len = ft_strlen(conv) - 2;
	check_flag(&flag, conv, ap);
	if (conv[len] == '%')
		return (ft_itoa(va_arg(ap, int)));
	if (is_tflag(conv[len]))
	{
		if ((len = cvt_flag_di(conv, ap, &str, len)) < 0)
			return (NULL);
	}
	else
		str = ft_itoa(va_arg(ap, int));
	if (*str == '-')
	{
		flag.blank = 0;
		flag.negative = 1;
		if (flag.zero || flag.dot)
			str = take_minus(str);
	}
	flag.is_signed = 1;
	str = width_prec_fill(flag, str);
	return (str);
}

char		*format_i(va_list ap, char *conv)
{
	int		i;

	i = 0;
	while (conv[i])
	{
		if (conv[i] == 'i')
			return (flag_i(conv, ap));
		i++;
	}
	return (NULL);
}
