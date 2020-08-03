/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:15:54 by lpadisha          #+#    #+#             */
/*   Updated: 2020/07/27 19:31:37 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBPRINTF_H
# define FT_LIBPRINTF_H
# define CONSTTYPE "cspdiuxXn%"
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct		s_flags
{
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				star;
}					t_flags;

size_t				g_nmbs;
int					ft_printf(const char *format, ...);
int					ft_check_flags(char c);
void				ft_print_main(t_flags flags, va_list args);
void				ft_print_width(int width, int min, int itsnul);
void				ft_str_end(char *str, int prec);
void				ft_print_char(char c, t_flags flags);
void				ft_print_string(char *str, t_flags flags);
void				ft_print_int(int i, t_flags flags);
void				ft_print_percent(t_flags flags);
void				ft_print_hex(unsigned int ui, char c, t_flags flags);
void				ft_print_uint(unsigned int unsi, t_flags flags);
void				ft_print_pointer(unsigned long long pointer, t_flags flags);
void				ft_charprint(int c, size_t m);
const char			*ft_flag_parse(const char *temp, t_flags *flags,
	va_list args);
char				*ft_baseull(unsigned long long ull, int base);
char				*ft_itoa_unsi(unsigned int n);
char				*ft_tolower_s(char *str);
t_flags				ft_minus_get(t_flags flags);
t_flags				ft_width_get(va_list args, t_flags flags);
t_flags				ft_digit_get(char c, t_flags flags);
const char			*ft_dot_get(const char *temp, t_flags *flags, va_list args);

#endif
