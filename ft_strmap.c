/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 12:27:21 by syamada           #+#    #+#             */
/*   Updated: 2018/07/16 13:37:02 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*m_s;
	int		i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if (!(m_s = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		m_s[i] = f(s[i]);
		i++;
	}
	m_s[i] = '\0';
	return (m_s);
}
