/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:43:11 by syamada           #+#    #+#             */
/*   Updated: 2018/07/23 19:21:52 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*rev;
	size_t	len;
	int		i;

	len = ft_strlen(str);
	rev = ft_strnew(len);
	i = 0;
	while (len)
		rev[i++] = str[--len];
	rev[i] = '\0';
	return (rev);
}
