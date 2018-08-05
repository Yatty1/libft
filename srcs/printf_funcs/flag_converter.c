/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 21:09:22 by syamada           #+#    #+#             */
/*   Updated: 2018/08/04 17:49:02 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*take_flag(char *conv, int len)
{
	int		i;
	char	*flag;

	i = 0;
	while (!ft_isdigit(conv[len]) && !is_stop(conv[len]) && len > 0)
	{
		len--;
		i++;
	}
	if (!(flag = ft_strsub(conv, len + 1, i)))
		return (NULL);
	return (flag);
}

int			cvt_flag_di(char *conv, va_list ap, char **str, int len)
{
	char	*flag;

	if (!(flag = take_flag(conv, len)))
		return (-1);
	if (ft_strcmp(flag, "hh") == 0)
		*str = ft_itoa((char)va_arg(ap, int));
	else if (ft_strcmp(flag, "h") == 0)
		*str = ft_itoa((short)va_arg(ap, int));
	else if (ft_strcmp(flag, "l") == 0)
		*str = ft_ltoa_base(va_arg(ap, long), 10, 0);
	else if (ft_strcmp(flag, "ll") == 0)
		*str = ft_lltoa(va_arg(ap, long long));
	else if (ft_strcmp(flag, "j") == 0)
		*str = ft_imaxtoa(va_arg(ap, intmax_t));
	else if (ft_strcmp(flag, "z") == 0)
		*str = ft_lltoa(va_arg(ap, size_t));
	free(flag);
	if (!*str)
		return (-1);
	return (len);
}
