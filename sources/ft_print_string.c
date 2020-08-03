/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 23:43:53 by lpadisha          #+#    #+#             */
/*   Updated: 2020/07/25 23:43:55 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

static void		ft_print_string_end(char *str, t_flags flags)
{
	if (flags.dot >= 0)
	{
		ft_print_width(flags.dot, ft_strlen(str), 0);
		ft_str_end(str, flags.dot);
	}
	else
		ft_str_end(str, ft_strlen(str));
	return ;
}

void			ft_print_string(char *str, t_flags flags)
{
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		ft_print_string_end(str, flags);
	if (flags.dot >= 0)
		ft_print_width(flags.width, flags.dot, 0);
	else
		ft_print_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		ft_print_string_end(str, flags);
	return ;
}
