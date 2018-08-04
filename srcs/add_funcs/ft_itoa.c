/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:40:06 by syamada           #+#    #+#             */
/*   Updated: 2018/08/02 15:00:27 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_minus(int *n)
{
	int		is_minus;

	is_minus = 0;
	if (*n < 0)
	{
		is_minus = 1;
		*n *= -1;
	}
	return (is_minus);
}

static int	get_len(int num, int is_minus)
{
	int	i;

	i = 2;
	while ((num /= 10) > 0)
		i++;
	i += is_minus;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		is_minus;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_minus = check_minus(&n);
	i = get_len(n, is_minus);
	if (!(str = ft_strnew(sizeof(i) + 1)))
		return (NULL);
	str[--i] = '\0';
	while (i--)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	if (is_minus)
		str[0] = '-';
	return (str);
}
