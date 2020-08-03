/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 02:12:04 by lpadisha          #+#    #+#             */
/*   Updated: 2020/05/20 04:59:24 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_char_to_itoa(int n, char *temp, size_t flag, unsigned int size)
{
	unsigned int	i;
	unsigned int	numbers;

	i = 0;
	if (flag == 1)
	{
		temp[i] = '-';
		i++;
		numbers = n * -1;
		size++;
	}
	else
		numbers = n;
	temp[size] = '\0';
	size--;
	while (size >= i)
	{
		temp[size] = numbers % 10 + '0';
		numbers /= 10;
		if (size == 0)
			break ;
		size--;
	}
	return (temp);
}

char	*ft_itoa(int n)
{
	char			*temp;
	unsigned int	numbers;
	size_t			flag;
	size_t			size;

	flag = 0;
	size = 0;
	if (n >= 0)
		numbers = n;
	else
	{
		numbers = n * -1;
		flag = 1;
	}
	if (numbers == 0)
		size++;
	while (numbers > 0)
	{
		numbers /= 10;
		size++;
	}
	if (!(temp = (char *)malloc(sizeof(char) * (size + 1 + flag))))
		return (NULL);
	return (ft_char_to_itoa(n, temp, flag, (unsigned int)size));
}
