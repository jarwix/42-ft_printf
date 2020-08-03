/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 23:42:40 by lpadisha          #+#    #+#             */
/*   Updated: 2020/07/27 17:20:31 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

t_flags		ft_minus_get(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags		ft_digit_get(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

t_flags		ft_width_get(va_list args, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
	}
	return (flags);
}

const char	*ft_dot_get(const char *temp, t_flags *flags, va_list args)
{
	temp++;
	if (*temp == '*')
	{
		flags->dot = va_arg(args, int);
		temp++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(*temp))
		{
			flags->dot = (flags->dot * 10) + (*temp - '0');
			temp++;
		}
	}
	return (temp);
}
