/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 18:07:00 by jbalestr          #+#    #+#             */
/*   Updated: 2015/01/13 12:36:03 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_whitespace(char const c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		len;

	if (!s)
		return (NULL);
	while (*s && ft_is_whitespace(*s))
		s++;
	len = ft_strlen((char *)s) - 1;
	while (len > 0 && s[len] && ft_is_whitespace(s[len]))
		len--;
	return (ft_strsub(s, 0, len + 1));
}
