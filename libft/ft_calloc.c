/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:49:15 by lpadisha          #+#    #+#             */
/*   Updated: 2020/05/22 06:42:56 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*memory;

	if (!(memory = (char *)malloc(size * num)))
		return (NULL);
	ft_memset(memory, 0, (size * num));
	return ((void*)memory);
}
