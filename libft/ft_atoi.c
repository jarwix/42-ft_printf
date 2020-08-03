/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 01:41:08 by lpadisha          #+#    #+#             */
/*   Updated: 2020/05/24 00:36:26 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_num(unsigned long long num, int negative)
{
	if (num == 2147483648 && negative == -1)
		return ((int)num * negative);
	if (num > 2147483647)
	{
		if (negative == 1)
			return (-1);
		else
			return (0);
	}
	return ((int)num * negative);
}

int		ft_atoi(const char *str)
{
	int						i;
	int						negative;
	unsigned long long		ch;

	ch = 0;
	i = 0;
	while ((str[i]) && ((((str[i] >= 9) && (str[i] <= 13)) || (str[i] == 32))))
		i++;
	negative = 1;
	if (str[i] == '-')
		negative = -1;
	if ((str[i] == '+') || (str[i] == '-'))
		i++;
	while ((str[i]) && (str[i] >= '0') && (str[i] <= '9'))
	{
		ch = ch * 10 + (str[i] - '0');
		i++;
	}
	return (check_num(ch, negative));
}
