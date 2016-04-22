/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 19:22:52 by tpelago           #+#    #+#             */
/*   Updated: 2016/01/18 18:02:36 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *new_list;
	t_list *result;

	new_list = NULL;
	while (lst)
	{
		tmp = f(lst);
		if (!new_list)
		{
			new_list = tmp;
			result = new_list;
			new_list->next = NULL;
		}
		else
		{
			new_list->next = tmp;
			tmp->next = NULL;
			new_list = new_list->next;
		}
		lst = lst->next;
	}
	return (result);
}
