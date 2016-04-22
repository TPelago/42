/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 18:56:37 by tpelago           #+#    #+#             */
/*   Updated: 2015/01/13 12:36:39 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static size_t	count_strings(char *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			word++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (word);
}

static char		*ft_strdup_mod(char *s, char c)
{
	static size_t	i = 0;
	size_t			word_len;

	word_len = 0;
	while (s[i] != 0 && s[i] == c)
		i++;
	while (s[i] != 0 && s[i] != c)
	{
		word_len++;
		i++;
	}
	return (ft_strsub(s, i - word_len, word_len));
}

static int		is_there_delimitator(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**array;
	size_t		word;
	size_t		i;

	i = 0;
	word = count_strings((char *)s, c);
	array = malloc(sizeof(char *) * (word + 1));
	if (array)
	{
		while (i < word)
		{
			if (is_there_delimitator((char *)s, c) == 0)
			{
				array[0] = (char *)s;
				array[1] = NULL;
				return (array);
			}
			array[i] = ft_strdup_mod((char *)s, c);
			i++;
		}
		array[i] = 0;
	}
	return (array);
}
