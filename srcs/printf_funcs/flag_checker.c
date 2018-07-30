/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 20:52:55 by syamada           #+#    #+#             */
/*   Updated: 2018/07/30 11:21:50 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_tflag(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

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
	flag->blank = ft_strchr(conv, ' ') ? 1 : 0;
	flag->hash = ft_strchr(conv, '#') ? 1 : 0;
	while (len > 0)
	{
		while (!is_stop(conv[len]))
			len--;
		flag->zero = conv[len + 1] == '0' ? 1 : 0;
		if (flag->zero)
			break ;
		len--;
	}
	flag->zero_processed = 0;
}
