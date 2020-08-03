/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 20:36:27 by lpadisha          #+#    #+#             */
/*   Updated: 2020/05/12 19:17:59 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t				i;
	const unsigned char	*tmp1;
	const unsigned char	*tmp2;

	i = 0;
	if (arr1 == arr2 || n == 0)
		return (0);
	tmp1 = (const unsigned char *)arr1;
	tmp2 = (const unsigned char *)arr2;
	while (i < n)
	{
		if ((tmp1[i]) != (tmp2[i]))
			return (tmp1[i] - tmp2[i]);
		i++;
	}
	return (0);
}
