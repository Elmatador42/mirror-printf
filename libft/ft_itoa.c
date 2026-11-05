/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arngomes <arngomes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:07:12 by arngomes          #+#    #+#             */
/*   Updated: 2026/11/04 18:21:40 by arngomes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_len(long n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nb;
	size_t	l;

	nb = n;
	l = num_len(nb);
	res = malloc((l + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[l] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	while (l > (size_t)(n < 0))
	{
		res[--l] = nb % 10 + '0';
		nb /= 10;
	}
	return (res);
}
