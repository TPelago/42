/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 13:54:49 by tpelago           #+#    #+#             */
/*   Updated: 2016/03/16 13:29:35 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	int		overlap_direction;

	overlap_direction = 0;
	if (dst < src)
	{
		d = (char *)dst;
		s = (char *)src;
		overlap_direction = 1;
	}
	else if (dst > src)
	{
		d = (char *)dst + len - 1;
		s = (char *)src + len - 1;
		overlap_direction = -1;
	}
	while (overlap_direction != 0 && len--)
	{
		*d = *s;
		d += overlap_direction;
		s += overlap_direction;
	}
	return (dst);
}
