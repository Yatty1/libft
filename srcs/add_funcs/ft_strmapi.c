/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 12:49:37 by syamada           #+#    #+#             */
/*   Updated: 2018/07/16 13:37:08 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	size_t	len;
	char	*m_s;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if (!(m_s = ft_strnew(len)))
		return (NULL);
	while (s[i])
	{
		m_s[i] = f(i, s[i]);
		i++;
	}
	return (m_s);
}
