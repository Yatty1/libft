/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:32:50 by syamada           #+#    #+#             */
/*   Updated: 2018/07/23 19:19:12 by syamada          ###   ########.fr       */
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

int				ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	result;
	unsigned long long	max;

	result = 0;
	max = 9223372036854775807;
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
	if ((sign == 1 && result > max) || (sign < 0 && result > max + 1))
		return ((sign < 0) ? 0 : -1);
	return (sign * result);
}
