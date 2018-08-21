/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:13:05 by syamada           #+#    #+#             */
/*   Updated: 2018/08/07 14:14:02 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_space(char c)
{
	if (c == '\v' || c == '\f' || c == '\r' || c == ' '
			|| c == '\n' || c == '\t')
		return (1);
	return (0);
}

long			ft_atol(const char *str)
{
	int		sign;
	long	result;

	result = 0;
	while (is_space(*str))
		str++;
	sign = 1;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return (sign * result);
}
