/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 18:54:00 by syamada           #+#    #+#             */
/*   Updated: 2018/07/27 22:32:47 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_charstr(char c)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(2);
	str[i++] = c;
	str[i] = '\0';
	return (str);
}
