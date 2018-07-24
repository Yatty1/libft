/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 20:12:25 by syamada           #+#    #+#             */
/*   Updated: 2018/07/14 14:54:47 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	int		len;

	last = NULL;
	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (*s == c)
			last = (char *)s;
		s++;
	}
	return (last);
}
