/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 23:00:19 by lpadisha          #+#    #+#             */
/*   Updated: 2020/07/27 17:20:04 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

void		ft_str_end(char *str, int end)
{
	int		i;

	i = 0;
	while (str[i] && i < end)
		ft_charprint(str[i++], 0);
	return ;
}

void		ft_charprint(int c, size_t m)
{
	ft_putchar_fd(c, 1);
	if (m == 0)
		g_nmbs++;
	return ;
}
