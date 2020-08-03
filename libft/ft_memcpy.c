/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 01:37:40 by lpadisha          #+#    #+#             */
/*   Updated: 2020/05/22 06:26:06 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*tmp1;
	const unsigned char	*tmp2;
	size_t				i;

	i = 0;
	tmp1 = (unsigned char*)dst;
	tmp2 = (unsigned char*)src;
	if (!n || tmp1 == tmp2)
		return (dst);
	while (i < n)
	{
		*(tmp1++) = *(tmp2++);
		i++;
	}
	return (dst);
}
