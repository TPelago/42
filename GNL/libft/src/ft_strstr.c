/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 19:05:51 by tpelago           #+#    #+#             */
/*   Updated: 2015/01/13 11:52:53 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (*s2 == 0)
		return ((char *)s1);
	while (s1[i] && s2 && s1[i] != s2[j])
	{
		i++;
		if (s1[i] && s2 && s1[i] == s2[j])
		{
			if (ft_strnequ((char *)s1 + i, (char *)s2, ft_strlen((char *)s2)))
				return ((char *)s1 + i);
		}
	}
	return (0);
}
