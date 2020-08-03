/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:10:53 by lpadisha          #+#    #+#             */
/*   Updated: 2020/05/15 04:20:01 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	const char	*temp;

	temp = str;
	while (*temp)
		temp++;
	if (ch == '\0')
		return ((char*)temp);
	while (!(--temp < str))
	{
		if (*temp == ch)
			return ((char *)temp);
	}
	return (NULL);
}
