/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arngomes <arngomes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 13:59:03 by arngomes          #+#    #+#             */
/*   Updated: 2026/11/12 14:36:32 by arngomes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_hex(unsigned long n, int upper)
{
	char	*base;
	int		len;

	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += ft_convert_hex(n / 16, upper);
	ft_putchar_fd(base[n % 16], 1);
	return (len + 1);
}

int	ft_print_hex(unsigned int n, int upper)
{
	return (ft_convert_hex(n, upper));
}

int	ft_print_ptr(void *ptr)
{
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	return (2 + ft_convert_hex((unsigned long)ptr, 0));
}
