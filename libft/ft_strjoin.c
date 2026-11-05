/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arngomes <arngomes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:28:25 by arngomes          #+#    #+#             */
/*   Updated: 2026/11/04 17:58:22 by arngomes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	slen;
	size_t	dlen;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	slen = ft_strlen(s1);
	dlen = ft_strlen(s2);
	str = malloc((slen + dlen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, slen);
	ft_memcpy(str + slen, s2, dlen);
	str[slen + dlen] = '\0';
	return (str);
}
