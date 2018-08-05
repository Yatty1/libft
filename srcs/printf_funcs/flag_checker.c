/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 20:52:55 by syamada           #+#    #+#             */
/*   Updated: 2018/08/05 15:55:07 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_helper(char *conv, int *len)
{
	int		i;

	i = 0;
	while (!is_stop(conv[*len]))
	{
		i++;
		*len -= 1;
	}
	return (i);
}

static int	get_width_prec(char *conv, t_flag *flag, va_list ap)
{
	int		len;
	int		i;
	char	*tmp;

	len = ft_strlen(conv) - 2;
	flag->width = 0;
	flag->precision = 0;
	while (conv[len] != '*' && !ft_isdigit(conv[len]) && len > 0)
		len--;
	while (len > 0)
	{
		i = count_helper(conv, &len);
		if (!(tmp = ft_strsub(conv, len + 1, i)))
			return (-1);
		if (conv[len] == '.')
			flag->precision = *tmp == '*' ? va_arg(ap, int) : ft_atoi(tmp);
		else
			flag->width = *tmp == '*' ? va_arg(ap, int) : ft_atoi(tmp);
		free(tmp);
		if (flag->width != 0)
			break ;
		len--;
	}
	return (i);
}

void		check_flag(t_flag *flag, char *conv, va_list ap)
{
	int		len;

	len = ft_strlen(conv) - 1;
	get_width_prec(conv, flag, ap);
	flag->plus = ft_strchr(conv, '+') ? 1 : 0;
	flag->minus = ft_strchr(conv, '-') ? 1 : 0;
	flag->dot = ft_strchr(conv, '.') ? 1 : 0;
	flag->blank = ft_strchr(conv, ' ') && !flag->plus ? 1 : 0;
	flag->hash = ft_strchr(conv, '#') ? 1 : 0;
	flag->str = 0;
	flag->octal = 0;
	flag->negative = 0;
	flag->zero_processed = 0;
	flag->is_signed = 0;
	flag->is_cap = 0;
	while (len > 0)
	{
		while (!is_stop(conv[len]))
			len--;
		flag->zero = conv[len + 1] == '0' && !flag->minus ? 1 : 0;
		if (flag->zero)
			break ;
		len--;
	}
}
