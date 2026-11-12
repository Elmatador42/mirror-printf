/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arngomes <arngomes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:34:25 by arngomes          #+#    #+#             */
/*   Updated: 2026/11/05 14:35:45 by arngomes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_format(va_list args, const char let);
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_ptr(void *ptr);
int	ft_nbrlen(int n);
int	ft_print_int(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_convert_hex(unsigned long n, int upper);
int	ft_print_hex(unsigned int n, int upper);

#endif
