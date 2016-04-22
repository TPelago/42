/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 15:08:21 by tpelago           #+#    #+#             */
/*   Updated: 2015/01/08 15:12:36 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		*copy;

	i = 0;
	copy = 0;
	if (c == 0)
		return ((char *)s + ft_strlen((char *)s));
	while (s[i])
	{
		if (s[i] == (char)c)
			copy = ((char *)s + i);
		i++;
	}
	return (copy);
}
