/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_and_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 22:56:04 by lpadisha          #+#    #+#             */
/*   Updated: 2020/07/27 04:10:43 by lpadisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

static char		*change_base(unsigned long long ulltemp, int base,
int i, char *ch_temp)
{
	while (ulltemp != 0)
	{
		if ((ulltemp % base) < 10)
			ch_temp[i - 1] = (ulltemp % base) + 48;
		else
			ch_temp[i - 1] = (ulltemp % base) + 55;
		ulltemp /= base;
		i--;
	}
	return (ch_temp);
}

static int		ft_count_n(long num)
{
	int		isneg;
	size_t	count;

	count = 0;
	isneg = 0;
	if (num < 0)
	{
		isneg++;
		count++;
		num = num * (-1);
	}
	while (num >= 1)
	{
		count++;
		num /= 10;
	}
	return (count);
}

static char		*ft_create_num(char *charnum, long nbr, int isneg, int i)
{
	if (nbr == 0)
		return (charnum = ft_strdup("0"));
	else
	{
		if (!(charnum = malloc(sizeof(char) * (i + 1))))
			return (0);
	}
	isneg = 0;
	if (nbr < 0)
	{
		isneg++;
		nbr = nbr * (-1);
	}
	charnum[i] = '\0';
	while (--i)
	{
		charnum[i] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (isneg == 1)
		charnum[0] = '-';
	else
		charnum[0] = (nbr % 10) + '0';
	return (charnum);
}

char			*ft_baseull(unsigned long long ull, int base)
{
	char				*ch_temp;
	unsigned long long	ulltemp;
	int					i;

	i = 0;
	ch_temp = 0;
	ulltemp = ull;
	if (ull == 0)
		return (ft_strdup("0"));
	while (ull != 0)
	{
		ull /= base;
		i++;
	}
	if (!(ch_temp = malloc(sizeof(char) * (i + 1))))
		return (0);
	ch_temp[i] = '\0';
	ch_temp = change_base(ulltemp, base, i, ch_temp);
	return (ch_temp);
}

char			*ft_itoa_unsi(unsigned int n)
{
	long	nbr;
	int		isneg;
	int		i;
	char	*charnum;

	nbr = n;
	i = ft_count_n(nbr);
	charnum = 0;
	isneg = 0;
	if (!(charnum = ft_create_num(charnum, nbr, isneg, i)))
		return (0);
	return (charnum);
}
