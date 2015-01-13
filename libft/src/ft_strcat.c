/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 14:35:55 by tpelago           #+#    #+#             */
/*   Updated: 2015/01/08 14:44:02 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	size_t		i;
	size_t		j;
	char		*s2cpy;

	s2cpy = (char *)s2;
	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2cpy[j])
	{
		s1[i] = s2cpy[j];
		i++;
		j++;
	}
	s1[i] = 0;
	return (s1);
}
