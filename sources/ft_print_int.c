/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 23:43:08 by lpadisha          #+#    #+#             */
/*   Updated: 2020/07/27 17:21:53 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

static void	ft_print_int_end_2(char *i_char, t_flags flags, int save_i)
{
	if (save_i < 0 && flags.dot >= 0)
		ft_charprint('-', 0);
	if (flags.dot >= 0)
		ft_print_width(flags.dot - 1, ft_strlen(i_char) - 1, 1);
	ft_str_end(i_char, ft_strlen(i_char));
	return ;
}

static void	ft_print_int_end(char *i_char, t_flags flags, int save_i)
{
	if (flags.minus == 1)
		ft_print_int_end_2(i_char, flags, save_i);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(i_char))
		flags.dot = ft_strlen(i_char);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		ft_print_width(flags.width, 0, 0);
	}
	else
		ft_print_width(flags.width, ft_strlen(i_char), flags.zero);
	if (flags.minus == 0)
		ft_print_int_end_2(i_char, flags, save_i);
	free(i_char);
	return ;
}

void		ft_print_int(int i, t_flags flags)
{
	char	*i_char;
	int		save_i;

	save_i = i;
	if (flags.dot == 0 && i == 0)
	{
		ft_print_width(flags.width, 0, 0);
		return ;
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot == -1)
			ft_str_end("-", 1);
		flags.zero = 1;
		i = i * (-1);
		flags.width--;
	}
	i_char = ft_itoa(i);
	ft_print_int_end(i_char, flags, save_i);
	return ;
}
