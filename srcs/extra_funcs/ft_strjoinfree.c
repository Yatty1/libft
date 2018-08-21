/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 17:56:36 by syamada           #+#    #+#             */
/*   Updated: 2018/08/13 13:16:15 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinfree(char *s1, char *s2)
{
	char	*j_s;

	j_s = ft_strjoin(s1, s2);
	ft_strdel((char **)&s1);
	ft_strdel((char **)&s2);
	return (j_s);
}
