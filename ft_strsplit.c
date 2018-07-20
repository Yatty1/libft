/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 14:24:45 by syamada           #+#    #+#             */
/*   Updated: 2018/07/16 14:27:28 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_w(char *s, char c)
{
	int		i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			i++;
			while (*s != c && *s)
				s++;
		}
		if (*s)
			s++;
	}
	return (i);
}

static int	count_char(char *s, char c, int i)
{
	int		count;

	count = 0;
	while (s[i] != c && s[i])
	{
		i++;
		count++;
	}
	return (count);
}

static void	assign_str(char *str, char *s, char c, int *i)
{
	int		k;

	k = 0;
	while (s[*i] != c && s[*i])
	{
		str[k++] = s[*i];
		*i = *i + 1;
	}
	str[k] = '\0';
}

char		**ft_strsplit(char const *s, char c)
{
	char	**a_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (!(a_str = (char **)malloc(sizeof(char *) * c_w((char *)s, c) + 1)))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			if (!(a_str[j] = ft_strnew(count_char((char *)s, c, i))))
				return (NULL);
			a_str[j] = ft_strnew(count_char((char *)s, c, i));
			assign_str(a_str[j], (char *)s, c, &i);
			j++;
		}
	}
	a_str[j] = 0;
	return (a_str);
}
