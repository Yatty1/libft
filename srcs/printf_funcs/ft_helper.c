/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 15:41:17 by syamada           #+#    #+#             */
/*   Updated: 2018/08/05 23:33:14 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strjoinfree(char *s1, char *s2)
{
	char	*j_s;

	j_s = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (j_s);
}

char		*ft_strsubfree(char *str, int start, int len)
{
	char	*tmp;

	tmp = ft_strsub(str, start, len);
	free(str);
	return (tmp);
}

static void	null_helper(t_flag *flag, int *len)
{
	char	*wd;

	wd = NULL;
	if (flag->width > 1)
	{
		*len = flag->width - 1;
		wd = ft_memset(ft_strnew(flag->width - 1), ' ', flag->width - 1);
		flag->width = 0;
	}
	if (flag->minus && wd)
	{
		ft_putchar('\0');
		ft_putstr(wd);
	}
	else if (wd)
	{
		ft_putstr(wd);
		ft_putchar('\0');
	}
	else
		ft_putchar('\0');
	if (wd != NULL)
		free(wd);
}

char		*put_null(char *str, int *len, t_flag *flag)
{
	if (!str)
		return (ft_strdup(""));
	*len += ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	str = ft_strdup("");
	null_helper(flag, len);
	*len += 1;
	return (ft_strdup(""));
}
