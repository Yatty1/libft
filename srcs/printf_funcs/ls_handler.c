/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 13:22:12 by syamada           #+#    #+#             */
/*   Updated: 2018/08/05 15:19:32 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_wchar(char *str, wchar_t c)
{
	if (c <= 0x7f)
		str = ft_strappend(str, c);
	else if (c <= 0x7ff)
	{
		str = ft_strappend(str, (c >> 6) | 0xc0);
		str = ft_strappend(str, (c & 0x3f) | 0x80);
	}
	else if (c <= 0xffff)
	{
		str = ft_strappend(str, (c >> 12) | 0xe0);
		str = ft_strappend(str, (c >> 6 & 0x3f) | 0x80);
		str = ft_strappend(str, (c & 0x3f) | 0x80);
	}
	else if (c <= 0x10ffff)
	{
		str = ft_strappend(str, (c >> 18) | 0xf0);
		str = ft_strappend(str, ((c >> 12) & 0x3f) | 0x80);
		str = ft_strappend(str, ((c >> 6) & 0x3f) | 0x80);
		str = ft_strappend(str, (c & 0x3f) | 0x80);
	}
	return (str);
}

int		ft_wcharlen(wchar_t c)
{
	if (c <= 0x7f)
		return (1);
	else if (c <= 0x7ff)
		return (2);
	else if (c <= 0xffff)
		return (3);
	else if (c <= 0x10ffff)
		return (4);
	return (0);
}

int		ft_strwcharlen(wchar_t *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
		len += ft_wcharlen(str[i++]);
	return (len);
}

char	*ft_strwchar(wchar_t *str)
{
	char	*s;
	char	*buf;
	char	*tmp;
	int		i;

	i = 0;
	buf = NULL;
	tmp = NULL;
	s = ft_strnew(ft_strwcharlen(str));
	while (str[i])
	{
		buf = ft_wchar(ft_strnew(1), str[i]);
		tmp = ft_strjoin(s, buf);
		free(buf);
		free(s);
		s = tmp;
		i++;
	}
	return (s);
}
