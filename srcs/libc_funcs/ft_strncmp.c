/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:21:18 by syamada           #+#    #+#             */
/*   Updated: 2018/07/23 21:24:39 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*c_s1;
	unsigned char	*c_s2;
	size_t			i;

	i = 0;
	if (n == 0)
		return (0);
	c_s1 = (unsigned char *)s1;
	c_s2 = (unsigned char *)s2;
	while (*c_s1 == *c_s2 && *c_s1 != '\0' && *c_s2 != '\0' && ++i < n)
	{
		c_s1++;
		c_s2++;
	}
	return (*c_s1 - *c_s2);
}
