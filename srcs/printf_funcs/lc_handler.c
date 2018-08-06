/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lc_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 13:36:36 by syamada           #+#    #+#             */
/*   Updated: 2018/08/05 13:37:10 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwchar(wchar_t c)
{
	if (c <= 0x7f)
		ft_putchar(c);
	else if (c <= 0x7ff)
	{
		ft_putchar((c >> 6) | 0xc0);
		ft_putchar((c & 0x3f) | 0x80);
	}
	else if (c <= 0xffff)
	{
		ft_putchar((c >> 12) | 0xe0);
		ft_putchar((c >> 6 & 0x3f) | 0x80);
		ft_putchar((c & 0x3f) | 0x80);
	}
	else if (c <= 0x10ffff)
	{
		ft_putchar((c >> 18) | 0xf0);
		ft_putchar(((c >> 12) & 0x3f) | 0x80);
		ft_putchar(((c >> 6) & 0x3f) | 0x80);
		ft_putchar((c & 0x3f) | 0x80);
	}
}
