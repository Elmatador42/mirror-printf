/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arngomes <arngomes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:26:51 by arngomes          #+#    #+#             */
/*   Updated: 2026/11/12 13:52:10 by arngomes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char let)
{
	int	len;

	len = 0;
	if (let == 'c')
		len = ft_print_char(va_arg(args, int));
	else if (let == 's')
		len = ft_print_str(va_arg(args, char *));
	else if (let == 'p')
		len = ft_print_ptr(va_arg(args, void *));
	else if (let == 'd')
		len = ft_print_int(va_arg(args, int));
	else if (let == 'i')
		len = ft_print_int(va_arg(args, int));
	else if (let == 'u')
		len = ft_print_unsigned(va_arg(args, unsigned int));
	else if (let == 'x')
		len = ft_print_hex(va_arg(args, unsigned int), 0);
	else if (let == 'X')
		len = ft_print_hex(va_arg(args, unsigned int), 1);
	else if (let == '%')
		len = ft_print_char('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			len += ft_format(args, str[i + 1]);
			i++;
		}
		else
			len += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
