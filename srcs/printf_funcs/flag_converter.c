/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 21:09:22 by syamada           #+#    #+#             */
/*   Updated: 2018/08/01 21:12:52 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		cvt_flag_di(char *conv, va_list ap, char **str, int len)
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
		*str = ft_itoa(va_arg(ap, int));//signed char
	else if (ft_strcmp(flag, "h") == 0)
		*str = ft_itoa(va_arg(ap, int));//short
	else if (ft_strcmp(flag, "l") == 0)
		*str = ft_ltoa_base(va_arg(ap, long), 10, 0);//long
	else if (ft_strcmp(flag, "ll") == 0)
		*str = ft_lltoa_base(va_arg(ap, long long), 10, 0);//long long
	else if (ft_strcmp(flag, "j") == 0)
		*str = ft_lltoa_base(va_arg(ap, intmax_t), 10, 0);//intmax_t
	else if (ft_strcmp(flag, "z") == 0)
		*str = ft_uitoa_base(va_arg(ap, size_t), 10, 0);//size_t
	free(flag);
	if (!*str)
		return (-1);
	return (len);
}

int		cvt_flag_oux(char *conv, va_list ap, char **str, int len)
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
		*str = ft_itoa(va_arg(ap, int));//unsigned char
	else if (ft_strcmp(flag, "h") == 0)
		*str = ft_itoa(va_arg(ap, int));//unsigned short
	else if (ft_strcmp(flag, "l") == 0)
		*str = ft_ultoa_base(va_arg(ap, unsigned long), 10, 0);//unsigned long
	else if (ft_strcmp(flag, "ll") == 0)
		*str = ft_ulltoa_base(va_arg(ap, unsigned long long), 10, 0);//unsigned long long
	else if (ft_strcmp(flag, "j") == 0)
		*str = ft_ulltoa_base(va_arg(ap, uintmax_t), 10, 0);//uintmax_t
	else if (ft_strcmp(flag, "z") == 0)
		*str = ft_uitoa_base(va_arg(ap, size_t), 10, 0);//size_t
	free(flag);
	if (!*str)
		return (-1);
	return (len);
}
