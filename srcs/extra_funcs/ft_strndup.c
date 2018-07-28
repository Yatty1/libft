/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 21:42:34 by syamada           #+#    #+#             */
/*   Updated: 2018/07/27 18:53:59 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, int i, int n)
{
	int		j;
	char	*dup;

	j = 0;
	if (!(dup = (char *)malloc(sizeof(str) * (n + 1))))
		return (NULL);
	while (j < n && str[i])
		dup[j++] = str[i++];
	dup[j] = '\0';
	return (dup);
}
