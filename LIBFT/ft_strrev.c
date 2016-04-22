/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 12:11:38 by tpelago           #+#    #+#             */
/*   Updated: 2015/01/13 12:37:45 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strrev(char *str)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(str);
	i = 0;
	j = ft_strlen(str) - 1;
	new_str = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (new_str)
	{
		while (i < len)
		{
			new_str[i] = str[j];
			i++;
			j--;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}
