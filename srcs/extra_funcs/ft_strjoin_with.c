/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_with.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 17:25:01 by syamada           #+#    #+#             */
/*   Updated: 2018/07/23 17:32:28 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_with(const char *s1, const char *s2, char c)
{
	char	*str;
	size_t len;
	int		i;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 2;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	str[i++] = c;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
