/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 20:52:55 by syamada           #+#    #+#             */
/*   Updated: 2018/08/04 18:31:45 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_width_prec(char *conv, t_flag *flag)
{
	int		len;
	int		i;
	char	*tmp;

	i = 0;
	len = ft_strlen(conv) - 2;
	flag->width = 0;
	flag->precision = 0;
	while (!ft_isdigit(conv[len]) && len > 0)
		len--;
	while (len > 0)
	{
		while (!is_stop(conv[len]))
		{
			i++;
			len--;
		}
		if (!(tmp = ft_strsub(conv, len + 1, i)))
			return (-1);
		if (conv[len] == '.')
			flag->precision = ft_atoi(tmp);
		else
			flag->width = ft_atoi(tmp);
		free(tmp);
		if (flag->width != 0)
			break ;
		len--;
	}
	return (i);
}

void		check_flag(t_flag *flag, char *conv)
{
	int		len;

	len = ft_strlen(conv) - 1;
	get_width_prec(conv, flag);
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
