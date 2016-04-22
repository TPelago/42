/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 18:43:47 by tpelago           #+#    #+#             */
/*   Updated: 2016/01/18 15:13:45 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (elem)
	{
		if ((void *)content == 0)
		{
			elem->content = NULL;
			elem->content_size = 0;
		}
		else
		{
			elem->content = malloc(content_size);
			if (elem->content == 0)
			{
				elem->content_size = 0;
				return (elem);
			}
			elem->content_size = content_size;
			ft_memcpy(elem->content, content, content_size);
		}
		elem->next = NULL;
	}
	return (elem);
}
