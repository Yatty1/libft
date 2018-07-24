/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:16:25 by syamada           #+#    #+#             */
/*   Updated: 2018/07/23 17:22:24 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * count number of words in a string with delimiter.
 */

int		word_count(char *s, char d)
{
	int		i;

	i = 0;
	while (*s)
	{
		while (*s == d && *s)
			s++;
		if (*s != d && *s)
		{
			i++;
			while (*s != d && *s)
				s++;
		}
		if (*s)
			s++;
	}
	return (i);
}
