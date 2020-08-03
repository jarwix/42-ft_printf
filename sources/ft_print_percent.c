/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 23:43:22 by lpadisha          #+#    #+#             */
/*   Updated: 2020/07/27 17:17:23 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

void	ft_print_percent(t_flags flags)
{
	if (flags.minus == 1)
		ft_str_end("%", 1);
	ft_print_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		ft_str_end("%", 1);
	return ;
}
