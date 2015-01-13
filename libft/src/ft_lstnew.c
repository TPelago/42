/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 18:43:47 by tpelago           #+#    #+#             */
/*   Updated: 2015/01/13 12:37:30 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (elem)
	{
		elem->content = malloc(sizeof(content_size));
		elem->content = (void *)content;
		if ((void *)content == 0)
			elem->content_size = 0;
		else
			elem->content_size = content_size;
		elem->next = NULL;
	}
	return (elem);
}
