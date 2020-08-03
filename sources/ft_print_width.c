/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 23:44:21 by lpadisha          #+#    #+#             */
/*   Updated: 2020/07/27 17:22:23 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

void	ft_print_width(int width, int min, int zero_num)
{
	while (width - min > 0)
	{
		if (zero_num)
			ft_charprint('0', 0);
		else
			ft_charprint(' ', 0);
		min++;
	}
	return ;
}
