/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_with_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 17:59:09 by syamada           #+#    #+#             */
/*   Updated: 2018/08/13 13:15:14 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinfree_with(char *s1, char *s2, char c)
{
	char	*new;

	new = ft_strjoin_with(s1, s2, c);
	ft_strdel((char **)&s1);
	ft_strdel((char **)&s2);
	return (new);
}
