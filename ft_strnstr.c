/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 21:09:36 by syamada           #+#    #+#             */
/*   Updated: 2018/07/16 19:30:50 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*nd;
	size_t	n_len;

	nd = (char *)needle;
	n_len = ft_strlen(nd);
	if (*nd == '\0')
		return ((char *)haystack);
	while (*haystack && len-- >= n_len)
	{
		if ((*haystack == *nd) && (ft_strncmp(haystack, nd, n_len) == 0))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
