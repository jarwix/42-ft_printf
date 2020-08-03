/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 22:55:06 by lpadisha          #+#    #+#             */
/*   Updated: 2020/07/26 22:55:38 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

void	ft_print_main(t_flags flags, va_list args)
{
	char	c;

	c = (char)flags.type;
	if (c == 'c')
		ft_print_char(va_arg(args, int), flags);
	else if (c == 's')
		ft_print_string(va_arg(args, char *), flags);
	else if (c == 'p')
		ft_print_pointer(va_arg(args, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		ft_print_int(va_arg(args, int), flags);
	else if (c == 'u')
		ft_print_uint((unsigned int)va_arg(args, unsigned int),
		flags);
	else if (c == 'x' || c == 'X')
		ft_print_hex(va_arg(args, unsigned int), c, flags);
	else if (c == '%')
		ft_print_percent(flags);
	return ;
}
