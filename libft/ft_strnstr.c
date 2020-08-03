/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 15:24:42 by lpadisha          #+#    #+#             */
/*   Updated: 2020/05/17 21:50:30 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	l;
	size_t	m;

	if (s2[0] == '\0')
		return ((char *)s1);
	l = 0;
	while ((l < len) && (s1[l] != '\0'))
	{
		m = 0;
		while (s1[l + m] == s2[m] && s2[m] && l + m < len)
			m++;
		if (s2[m] == '\0')
			return ((char *)&s1[l]);
		l++;
	}
	return (0);
}
