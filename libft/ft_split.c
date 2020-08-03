/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 00:28:02 by lpadisha          #+#    #+#             */
/*   Updated: 2020/05/23 06:12:03 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**malloc_free(char **temp)
{
	unsigned int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
	return (NULL);
}

int		numbers_of_lines(char const *s, char c)
{
	int		i;
	int		numbers;

	i = 0;
	numbers = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		numbers++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (numbers);
}

void	ft_sp(char const *s, char *tmp_l, unsigned int i, unsigned int j)
{
	unsigned int		m;

	m = 0;
	while (j-- > 0)
		tmp_l[m++] = s[i - j - 1];
	tmp_l[m] = '\0';
}

char	**ft_split_end(char const *s, char c, char **tmp)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		l;

	i = 0;
	j = 0;
	l = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
		{
			i++;
			j++;
		}
		if (!(tmp[l] = (char *)malloc(sizeof(char) * (j + 1))))
			return (malloc_free(tmp));
		ft_sp(s, tmp[l], i, j);
		l++;
		j = 0;
		while (s[i] && s[i] == c)
			i++;
	}
	return (tmp);
}

char	**ft_split(char const *s, char c)
{
	char				**temp;
	unsigned int		number_lines;

	if (!s)
		return (NULL);
	number_lines = numbers_of_lines(s, c);
	if (!(temp = (char **)malloc(sizeof(char *) * (number_lines + 1))))
		return (NULL);
	ft_split_end(s, c, temp);
	temp[number_lines] = NULL;
	return (temp);
}
