/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 18:56:37 by tpelago           #+#    #+#             */
/*   Updated: 2015/10/05 17:48:03 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

static char		*ft_strdup_mod(char *s, char c, size_t *i)
{
	size_t			word_len;

	word_len = 0;
	while (s[*i] != 0 && s[*i] == c)
		(*i)++;
	while (s[*i] != 0 && s[*i] != c)
	{
		word_len++;
		(*i)++;
	}
	if (word_len == 0)
		return (NULL);
	return (ft_strsub(s, (*i) - word_len, word_len));
}

char			**ft_strsplit(char const *s, char c)
{
	char		**array;
	size_t		word;
	size_t		i;
	size_t		index;

	index = 0;
	i = 0;
	word = count_strings((char *)s, c);
	array = malloc(sizeof(char *) * (word + 1));
	if (array)
	{
		while (i < word)
		{
			array[i] = ft_strdup_mod((char *)s, c, &index);
			if (array[i] == NULL)
				return (array);
			i++;
		}
		array[i] = 0;
	}
	return (array);
}
