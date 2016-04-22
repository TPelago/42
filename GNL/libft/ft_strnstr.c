/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:09:35 by tpelago           #+#    #+#             */
/*   Updated: 2016/01/18 15:52:54 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0 || *s1 == 0)
		return (0);
	if (*s2 == 0)
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		if (ft_strnequ((char *)s1 + i, (char *)s2, n))
		{
			if (ft_strlen((char *)s2) + i > n)
				return (0);
			return ((char *)s1 + i);
		}
		i++;
	}
	return (0);
}
