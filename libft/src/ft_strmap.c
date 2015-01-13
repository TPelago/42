/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 16:54:19 by tpelago           #+#    #+#             */
/*   Updated: 2015/01/13 12:39:11 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t		i;
	char		*s2;

	s2 = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!s2)
		return (0);
	i = 0;
	while (s[i])
	{
		s2[i] = f(s[i]);
		i++;
	}
	s2[i] = 0;
	return (s2);
}
