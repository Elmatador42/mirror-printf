/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arngomes <arngomes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 13:22:54 by arngomes          #+#    #+#             */
/*   Updated: 2026/11/12 14:41:14 by arngomes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(int n)
{
	long	nb;
	int		len;

	nb = n;
	len = 0;
	if (n < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb >= 10)
	{
		len++;
		nb /= 10;
	}
	return (len + 1);
}

int	ft_print_int(int n)
{
	ft_putnbr_fd(n, 1);
	return (ft_nbrlen(n));
}

int	ft_print_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_print_unsigned(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
	return (len + 1);
}
