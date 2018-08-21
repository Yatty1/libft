/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:25:35 by syamada           #+#    #+#             */
/*   Updated: 2018/08/20 12:33:24 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strlast(char *str, char c)
{
	char	*last;

	last = str;
	while (*str)
	{
		if (*str == c && *(str + 1))
			last = ++str;
		if (*str)
			str++;
	}
	last = ft_strdup(last);
	return (last);
}
