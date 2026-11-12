/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arngomes <arngomes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:26:51 by arngomes          #+#    #+#             */
/*   Updated: 2026/11/12 13:22:32 by arngomes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_format(va_list args, const char let)
{
	int len;
	
	len = 0;
	if (let == 'c')
		len = ft_print_char(va_arg(args, char));
	else if (let == 's')
		len = ft_print_str(va_arg(args, char *));
	else if (let == 'p')
		len = 
	else if (let == 'd')
		len = ft_print_nbr(va_arg(args, ))
	else if (let == 'i')
		len = ft_print_int(va_arg(args, int))
	else if (let == 'u')
		len = 
	else if (let == 'x')
		len = 
	else if (let == 'X')
		len =
	else if (let == '%')
		len = 
	return (len)
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int len;
	int i;

	va_start(args, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			len += ft_format(args, str[i + 1]);
		else
			len++;
		i++;
	}
	va_end(args);
	return (len);
}
