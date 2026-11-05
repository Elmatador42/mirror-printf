/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arngomes <arngomes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:04:48 by arngomes          #+#    #+#             */
/*   Updated: 2026/11/04 18:07:03 by arngomes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			res++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (res);
}

static void	*free_all(char **res, size_t n)
{
	while (n > 0)
		free(res[--n]);
	free(res);
	return (NULL);
}

static char	*dup_word(char const *s, size_t k)
{
	char	*word;
	size_t	i;

	word = malloc((k + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < k)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	k;
	size_t	l;

	if (!s)
		return (NULL);
	res = ft_calloc(count_word(s, c) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	l = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		k = 0;
		while (s[k] && s[k] != c)
			k++;
		res[l] = dup_word(s, k);
		if (!res[l++])
			return (free_all(res, l - 1));
		s += k;
	}
	return (res);
}
