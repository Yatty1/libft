/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:57:54 by syamada           #+#    #+#             */
/*   Updated: 2018/07/19 21:20:11 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)malloc(sizeof(char) * n + 1);
	i = 0;
	while (i < n)
	{
		tmp[i] = s2[i];
		i++;
	}
	tmp[i] = '\0';
	ft_strcat(s1 + ft_strlen(s1), tmp);
	free(tmp);
	return (s1);
}
