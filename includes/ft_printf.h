/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 19:36:39 by syamada           #+#    #+#             */
/*   Updated: 2018/08/01 23:24:16 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
#include <stdio.h>

typedef struct	s_flag
{
	int		negative;
	int		zero_processed;
	int		str;
	int		octal;
	int		width;
	int		precision;
	int		zero;
	int		plus;
	int		minus;
	int		dot;
	int		blank;
	int		hash;
}				t_flag;

int				ft_printf(const char *format, ...);
char			*check_conv(va_list ap, char *conv);
char			*str_parser(char *fmt, char **str);
char			*format_parser(char *fmt, char **str, va_list ap);
char			*format_s(va_list ap, char *conv);
char			*format_p(va_list ap, char *conv);
char			*format_d(va_list ap, char *conv);
char			*format_i(va_list ap, char *conv);
char			*format_o(va_list ap, char *conv);
char			*format_u(va_list ap, char *conv);
char			*format_x(va_list ap, char *conv);
char			*format_c(va_list ap, char *conv);
int				is_conversion(char c);
int				is_stop(char c);
int				is_tflag(char c);
void			check_flag(t_flag *flag, char *conv);
char			*width_prec_fill(t_flag flag, char *str);
char			*fill_width(char *str, t_flag flag);
char			*adjust_precision(char *str, t_flag *flag);
int				cvt_flag_oux(char *conv, va_list ap, char **str, int len);
int				cvt_flag_di(char *conv, va_list ap, char **str, int len);

#endif