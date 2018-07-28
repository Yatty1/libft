/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 13:15:21 by syamada           #+#    #+#             */
/*   Updated: 2018/07/26 19:35:13 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*s_s;
	unsigned int	i;
	int				j;

	if (s == NULL)
		return (NULL);
	if (!(s_s = ft_strnew(len)))
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && len--)
		s_s[j++] = s[i++];
	s_s[j] = '\0';
	return (s_s);
}
