/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 19:07:33 by tpelago           #+#    #+#             */
/*   Updated: 2015/01/13 12:37:12 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*start;
	t_list		*tmp;

	start = *alst;
	if (alst)
	{
		if (start)
		{
			while (*alst)
			{
				del((*alst)->content, (*alst)->content_size);
				tmp = *alst;
				free(tmp);
				(*alst) = (*alst)->next;
			}
			start = NULL;
		}
	}
}
