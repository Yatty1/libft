/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 20:37:23 by syamada           #+#    #+#             */
/*   Updated: 2018/07/27 18:05:14 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*hs;
	char	*nd;
	char	*tmp;

	nd = (char *)needle;
	hs = (char *)haystack;
	if (*nd == '\0')
		return (hs);
	while (*hs && *nd)
	{
		hs = (char *)haystack;
		tmp = nd;
		while (*haystack && *tmp && *haystack == *tmp)
		{
			haystack++;
			tmp++;
		}
		if (*tmp == '\0')
			return (hs);
		haystack = hs + 1;
	}
	return (NULL);
}
