/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 22:11:04 by syamada           #+#    #+#             */
/*   Updated: 2018/07/20 15:49:55 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		len;
	int		i;

	len = size + 1;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	i = 0;
	while (size--)
		str[i++] = '\0';
	str[i] = '\0';
	return (str);
}
