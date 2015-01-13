/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 13:54:49 by tpelago           #+#    #+#             */
/*   Updated: 2015/01/08 13:55:41 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	tmp[len];
	char	*s;

	i = 0;
	s = (char *)dst;
	while (i < len)
		tmp[i++] = *((char *)src++);
	while (i--)
		s[i] = tmp[i];
	return (dst);
}
