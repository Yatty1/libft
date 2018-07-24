/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 19:21:07 by syamada           #+#    #+#             */
/*   Updated: 2018/07/23 18:33:44 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strinit(char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (!(s = ft_strnew(ft_strlen(str))))
		return (NULL);
	while (*str)
		s[i++] = *str++;
	s[i] = '\0';
	return (s);
}
