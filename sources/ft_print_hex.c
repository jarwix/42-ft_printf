/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 23:42:54 by lpadisha          #+#    #+#             */
/*   Updated: 2020/07/27 17:18:18 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

static void		ft_print_hex_end(char *hex, t_flags flags)
{
	if (flags.minus == 1)
	{
		if (flags.dot >= 0)
			ft_print_width(flags.dot - 1, ft_strlen(hex) - 1, 1);
		ft_str_end(hex, ft_strlen(hex));
	}
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hex))
		flags.dot = ft_strlen(hex);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		ft_print_width(flags.width, 0, 0);
	}
	else
		ft_print_width(flags.width, ft_strlen(hex), flags.zero);
	if (flags.minus == 0)
	{
		if (flags.dot >= 0)
			ft_print_width(flags.dot - 1, ft_strlen(hex) - 1, 1);
		ft_str_end(hex, ft_strlen(hex));
	}
	return ;
}

void			ft_print_hex(unsigned int ui, char c, t_flags flags)
{
	char	*hex;

	ui = (unsigned int)(4294967296 + ui);
	if (flags.dot == 0 && ui == 0)
	{
		ft_print_width(flags.width, 0, 0);
		return ;
	}
	hex = ft_baseull((unsigned long long)ui, 16);
	if (c == 'x')
		hex = ft_tolower_s(hex);
	ft_print_hex_end(hex, flags);
	free(hex);
	return ;
}
