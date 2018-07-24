/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 13:46:32 by syamada           #+#    #+#             */
/*   Updated: 2018/07/16 13:43:52 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char			*t_s;
	int				i;
	unsigned int	last;
	unsigned int	start;

	i = 0;
	if (s == NULL)
		return (NULL);
	last = ft_strlen(s);
	while (is_space(s[i]))
		i++;
	start = i;
	while (s[i])
	{
		while (!is_space(s[i]) && s[i])
		{
			last = i;
			i++;
		}
		if (s[i])
			i++;
	}
	t_s = ft_strsub(s, start, (last + 1) - start);
	return (t_s);
}
