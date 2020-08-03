/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 04:08:07 by lpadisha          #+#    #+#             */
/*   Updated: 2020/05/15 04:19:22 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	const char	*temp;

	temp = str;
	while (*temp)
	{
		if (*temp == ch)
			return ((char *)temp);
		temp++;
	}
	if (ch == '\0')
		return ((char*)temp);
	return (NULL);
}
