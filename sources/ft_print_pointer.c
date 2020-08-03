/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 23:43:38 by lpadisha          #+#    #+#             */
/*   Updated: 2020/07/27 17:20:18 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

static void	ft_print_pointer_end(char *pointer, t_flags flags)
{
	ft_str_end("0x", 2);
	if (flags.dot >= 0)
	{
		ft_print_width(flags.dot, ft_strlen(pointer), 1);
		ft_str_end(pointer, flags.dot);
	}
	else
		ft_str_end(pointer, ft_strlen(pointer));
	return ;
}

void		ft_print_pointer(unsigned long long ull, t_flags flags)
{
	char	*pointer;

	if (ull == 0 && flags.dot == 0)
	{
		ft_str_end("0x", 2);
		ft_print_width(flags.width, 0, 1);
		return ;
	}
	pointer = ft_baseull(ull, 16);
	pointer = ft_tolower_s(pointer);
	if ((size_t)flags.dot < ft_strlen(pointer))
		flags.dot = ft_strlen(pointer);
	if (flags.minus == 1)
		ft_print_pointer_end(pointer, flags);
	ft_print_width(flags.width, ft_strlen(pointer) + 2, 0);
	if (flags.minus == 0)
		ft_print_pointer_end(pointer, flags);
	free(pointer);
	return ;
}
