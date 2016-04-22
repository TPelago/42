/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 11:10:45 by tpelago           #+#    #+#             */
/*   Updated: 2016/01/18 17:40:27 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = malloc(ft_strlen(s1) + 1);
	if (dest != NULL)
		ft_strcpy(dest, s1);
	return (dest);
}
