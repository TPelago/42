/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 19:22:52 by tpelago           #+#    #+#             */
/*   Updated: 2015/01/13 11:41:37 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

static t_list	*ft_list_push_back(t_list **begin_list, t_list *elem)
{
	t_list		*start;

	start = *begin_list;
	if (begin_list)
	{
		if (!*begin_list)
		{
			*begin_list = elem;
			return (start);
		}
		while ((*begin_list)->next)
			(*begin_list) = (*begin_list)->next;
		(*begin_list)->next = elem;
	}
	return (start);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new_list;
	t_list		*elem;

	new_list = NULL;
	while (lst)
	{
		elem = f(lst);
		ft_list_push_back(&new_list, elem);
		lst = lst->next;
	}
	return (new_list);
}
