/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 23:42:19 by lpadisha          #+#    #+#             */
/*   Updated: 2020/07/27 17:17:08 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

void	ft_print_char(char c, t_flags flags)
{
	if (flags.minus == 1)
		ft_charprint(c, 0);
	ft_print_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_charprint(c, 0);
	return ;
}
