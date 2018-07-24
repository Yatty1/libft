/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 19:04:55 by syamada           #+#    #+#             */
/*   Updated: 2018/07/23 19:11:50 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*c_src;
	unsigned char	*c_dst;
	unsigned char	c_c;

	c_src = (unsigned char *)src;
	c_dst = (unsigned char *)dst;
	c_c = (unsigned char)c;
	while (n-- > 0)
	{
		if ((*c_dst++ = *c_src++) == c_c)
			return (c_dst);
	}
	return (NULL);
}
