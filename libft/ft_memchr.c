/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 00:53:53 by lpadisha          #+#    #+#             */
/*   Updated: 2020/05/22 23:21:42 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	tmpc;
	unsigned char	*tmp;

	i = 0;
	tmpc = (unsigned char)c;
	tmp = (unsigned char *)s;
	while (i < n)
	{
		if (tmp[i] == tmpc)
			return (tmp + i);
		i++;
	}
	return (NULL);
}
