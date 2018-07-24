/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 13:36:06 by syamada           #+#    #+#             */
/*   Updated: 2018/07/23 17:24:55 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*j_s;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	if (!(j_s = ft_strnew(len)))
		return (NULL);
	while (s1[j])
		j_s[i++] = s1[j++];
	j = 0;
	while (s2[j])
		j_s[i++] = s2[j++];
	j_s[i] = '\0';
	return (j_s);
}
