/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:44:22 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/08 15:59:15 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	get_length(unsigned long long nb, int base)
{
	int					length;
	unsigned long long	temp_count;

	length = 0;
	temp_count = nb;
	while (temp_count != 0)
	{
		temp_count /= base;
		length++;
	}
	if (nb == 0)
		length = 1;
	return (length);
}

char	get_char(int n, char *base)
{
	return (base[n]);
}

unsigned long long	power(int x, int pow)
{
	unsigned long long	result;
	int					n;

	result = 1;
	n = 0;
	while (n++ < pow)
	{
		result *= x;
	}
	return (result);
}

unsigned char	*fill_number(int nb_len, unsigned long long nb, char *base,
	int base_len)
{
	int				i;
	int				digit;
	int				str_len;
	unsigned char	*itoad;

	i = -1;
	str_len = nb_len + (nb < 0) + 1;
	itoad = malloc(sizeof(*itoad) * str_len);
	if (itoad == 0)
		return (0);
	if (nb < 0)
	{
		itoad[0] = '-';
		nb *= -1;
		++i;
	}
	while (++i < str_len - 1)
	{
		digit = nb / power(base_len, nb_len - 1);
		itoad[i] = get_char(digit, base);
		nb -= digit * power(base_len, nb_len - 1);
		nb_len--;
	}
	itoad[i] = 0;
	return (itoad);
}

unsigned char	*ft_uitoa_base(unsigned long long nbr, char *base)
{
	int		origin_length;
	int		length_base;

	length_base = ft_strlen(base);
	origin_length = get_length(nbr, length_base);
	return (fill_number(origin_length, nbr, base, length_base));
}