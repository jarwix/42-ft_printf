/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 01:39:00 by lpadisha          #+#    #+#             */
/*   Updated: 2020/05/20 18:14:28 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	temp;

	if (fd < 0)
		return ;
	if (n == -217483648)
	{
		ft_putnbr_fd(-2, fd);
		ft_putnbr_fd(17483648, fd);
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		temp = n * -1;
	}
	else
		temp = n;
	if (temp >= 10)
		ft_putnbr_fd(temp / 10, fd);
	ft_putchar_fd((char)(temp % 10 + 48), fd);
}
