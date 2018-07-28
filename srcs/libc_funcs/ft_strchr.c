/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 20:05:53 by syamada           #+#    #+#             */
/*   Updated: 2018/07/28 13:43:24 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *c_s;

	c_s = (char *)s;
	while (*c_s)
	{
		if (*c_s == c)
			return (c_s);
		c_s++;
	}
	if (*c_s == c)
		return (c_s);
	return (NULL);
}
