/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 03:20:19 by lpadisha          #+#    #+#             */
/*   Updated: 2020/07/27 17:14:23 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libprintf.h"

t_flags		ft_null_flags(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

int			ft_check_flags(char c)
{
	if (c == '-' || c == '0' || c == ' ' || c == '.' || c == '*')
		return (1);
	else
		return (0);
}

const char	*ft_flag_parse(const char *temp, t_flags *flags, va_list args)
{
	while (*temp)
	{
		if (!ft_isdigit(*temp) && !ft_check_flags(*temp) &&
				!ft_strchr(CONSTTYPE, *temp))
			break ;
		if (*temp == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (*temp == '.')
			temp = ft_dot_get(temp, flags, args);
		if (*temp == '-')
			*flags = ft_minus_get(*flags);
		if (*temp == '*')
			*flags = ft_width_get(args, *flags);
		if (ft_isdigit(*temp))
			*flags = ft_digit_get(*temp, *flags);
		if (ft_strchr(CONSTTYPE, *temp))
		{
			flags->type = *temp;
			break ;
		}
		temp++;
	}
	return (temp);
}

int			ft_print_save(const char *format, va_list args)
{
	t_flags		flags;
	const char	*temp;

	temp = format;
	while (1)
	{
		flags = ft_null_flags();
		format = temp;
		if (!*temp)
			break ;
		else if (*temp == '%' && *(++format))
		{
			temp = ft_flag_parse(format, &flags, args);
			if (ft_strchr(CONSTTYPE, *temp))
				ft_print_main(flags, args);
			else if (*temp)
				ft_charprint(*temp, 0);
		}
		else if (*temp != '%')
			ft_charprint(*temp, 0);
		temp++;
	}
	return ((int)g_nmbs);
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	int			errorflag;
	const char	*temp;

	g_nmbs = 0;
	errorflag = 0;
	if (!format)
		return (-1);
	temp = ft_strdup(format);
	va_start(args, format);
	errorflag = ft_print_save(temp, args);
	va_end(args);
	free((char *)temp);
	return ((errorflag == -1) ? -1 : (int)g_nmbs);
}
