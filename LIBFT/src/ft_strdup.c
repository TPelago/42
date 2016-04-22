/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 11:10:45 by tpelago           #+#    #+#             */
/*   Updated: 2015/01/13 12:33:50 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strdup(char *s1)
{
	char	*dest;

	if (!s1)
		return (NULL);
	dest = malloc(ft_strlen(s1) + 1);
	if (dest != NULL)
		ft_strcpy(dest, s1);
	return (dest);
}
