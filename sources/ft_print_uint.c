/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 23:44:06 by lpadisha          #+#    #+#             */
/*   Updated: 2020/07/27 17:20:52 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

static void		ft_print_uint_end(char *unsi_int, t_flags flags)
{
	if (flags.minus == 1)
	{
		if (flags.dot >= 0)
			ft_print_width(flags.dot - 1, ft_strlen(unsi_int) - 1, 1);
		ft_str_end(unsi_int, ft_strlen(unsi_int));
	}
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(unsi_int))
		flags.dot = ft_strlen(unsi_int);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		ft_print_width(flags.width, 0, 0);
	}
	else
		ft_print_width(flags.width, ft_strlen(unsi_int), flags.zero);
	if (flags.minus == 0)
	{
		if (flags.dot >= 0)
			ft_print_width(flags.dot - 1, ft_strlen(unsi_int) - 1, 1);
		ft_str_end(unsi_int, ft_strlen(unsi_int));
	}
	return ;
}

void			ft_print_uint(unsigned int unsi, t_flags flags)
{
	char	*unsi_int;

	unsi = (unsigned int)(4294967296 + unsi);
	if (flags.dot == 0 && unsi == 0)
	{
		ft_print_width(flags.width, 0, 0);
		return ;
	}
	unsi_int = ft_itoa_unsi(unsi);
	ft_print_uint_end(unsi_int, flags);
	free(unsi_int);
	return ;
}
