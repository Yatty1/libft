/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 19:36:39 by syamada           #+#    #+#             */
/*   Updated: 2018/08/07 18:06:40 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <wchar.h>

typedef struct	s_flag
{
	int		negative;
	int		zero_processed;
	int		is_signed;
	int		is_cap;
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
char			*convert_format(va_list ap, const char *fmt, int *len);
char			*check_conv(va_list ap, char *conv, char *str, int *len);
char			*str_parser(char *fmt, char **str);
char			*format_parser(char *fmt, char **str, va_list ap, int *len);
char			*take_flag(char *conv, int len);
void			check_flag(t_flag *flag, char *conv, va_list ap);
char			*format_s(va_list ap, char *conv);
char			*format_p(va_list ap, char *conv);
char			*format_d(va_list ap, char *conv);
char			*format_i(va_list ap, char *conv);
char			*format_o(va_list ap, char *conv);
char			*format_u(va_list ap, char *conv);
char			*format_x(va_list ap, char *conv);
char			*format_c(va_list ap, char *conv, char *str, int *len);
char			*format_percent(va_list ap, char *conv);
int				cvt_flag_di(char *conv, va_list ap, char **str, int len);
int				is_conversion(char c);
int				is_stop(char c);
int				is_tflag(char c);
char			*width_prec_fill(t_flag flag, char *str);
char			*fill_width(char *str, t_flag flag);
char			*adjust_precision(char *str, t_flag *flag);
char			*ft_wchar(char *str, wchar_t c);
void			ft_putwchar(wchar_t c);
int				ft_wcharlen(wchar_t c);
int				ft_strwcharlen(wchar_t *len);
char			*ft_strwchar(wchar_t *str);
char			*ft_strsubfree(char *str, int start, int len);
char			*put_null(char *str, int *len, t_flag *flag);

#endif
