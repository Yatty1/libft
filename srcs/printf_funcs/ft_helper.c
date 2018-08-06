/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 15:41:17 by syamada           #+#    #+#             */
/*   Updated: 2018/08/05 17:23:49 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*j_s;

	j_s = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (j_s);
}

char	*ft_strsubfree(char *str, int start, int end)
{
	char	*tmp;

	tmp = ft_strsub(str, start, end);
	free(str);
	return (tmp);
}