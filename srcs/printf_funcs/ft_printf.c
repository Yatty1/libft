/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 19:35:54 by syamada           #+#    #+#             */
/*   Updated: 2018/08/01 13:01:43 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** transfer condition when it gets bigger.
** being called by format_parser.
*/

char	*conv_funcs(va_list ap, char *conv, int i)
{
	char	*(*f[14])(va_list ap, char *conv);

	if (i < 0 || i > 13)
		return (NULL);
	f[0] = &format_s;
	f[1] = &format_s;
	f[2] = &format_p;
	f[3] = &format_d;
	f[4] = &format_d;
	f[5] = &format_i;
	f[6] = &format_o;
	f[7] = &format_o;
	f[8] = &format_u;
	f[9] = &format_u;
	f[10] = &format_x;
	f[11] = &format_x;
	f[12] = &format_c;
	f[13] = &format_c;
	return (*f[i])(ap, conv);
}

char	*check_conv(va_list ap, char *conv)
{
	char	*conversions;
	int		i;
	int		j;

	i = 1;
	conversions = ft_strdup("sSpdDioOuUxXcC");
	while (conv[i])
	{
		/*
		if (conv[i] == 's' || conv[i] == 'S')
			return (format_s(ap, conv));
		if (conv[i] == 'p')
			return (format_p(ap, conv));
		if (conv[i] == 'd' || conv[i] == 'D')
			return (format_d(ap, conv));
		if (conv[i] == 'i')
			return (format_i(ap, conv));
		if (conv[i] == 'o' || conv[i] == 'O')
			return (format_o(ap, conv));
		if (conv[i] == 'u' || conv[i] == 'U')
			return (format_u(ap, conv));
		if (conv[i] == 'x' || conv[i] == 'X')
			return (format_x(ap, conv));
		if (conv[i] == 'c' || conv[i] == 'C')
			return (format_c(ap, conv));
		*/
		if (is_conversion(conv[i]))
		{
			j = 0;
			while (conversions[j] != conv[i])
				j++;
			free(conversions);
			return (conv_funcs(ap, conv, j));
		}
		if (conv[i] == '%')
			return (ft_charstr('%'));
		i++;
	}
	return (ft_strdup(""));
}

/*
** put extra parser to extend your printf
*/

char	*convert_format(va_list ap, const char *fmt)
{
	char	*str;

	while (*fmt)
	{
		if (!(fmt = str_parser((char *)fmt, &str)))
			break ;
		if (!(fmt = format_parser((char *)fmt, &str, ap)))
			return (NULL);
	}
	if (!str)
		return (NULL);
	return (str);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	char	*str;
	int		len;

	va_start(ap, format);
	if (!(str = convert_format(ap, format)))
		return (-1);
	va_end(ap);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
