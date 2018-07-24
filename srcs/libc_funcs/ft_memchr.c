/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 19:41:29 by syamada           #+#    #+#             */
/*   Updated: 2018/07/13 15:23:04 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *cs;

	cs = (unsigned char *)s;
	while (n--)
	{
		if (*cs == (unsigned char)c)
			return (cs);
		cs++;
	}
	return (NULL);
}
