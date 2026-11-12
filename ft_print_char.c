/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arngomes <arngomes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:52:29 by arngomes          #+#    #+#             */
/*   Updated: 2026/11/12 13:58:53 by arngomes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
