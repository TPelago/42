/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 19:05:51 by tpelago           #+#    #+#             */
/*   Updated: 2015/10/05 16:59:02 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t		i;

	i = 0;
	if (!(s2) || *s2 == 0)
		return ((char *)s1);
	while (s1[i])
	{
		if (s1[i] == *s2)
		{
			if (ft_strnequ((char *)s1 + i, (char *)s2, ft_strlen((char *)s2)))
				return ((char *)s1 + i);
		}
		i++;
	}
	return (0);
}
