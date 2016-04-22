/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 15:28:44 by tpelago           #+#    #+#             */
/*   Updated: 2016/01/18 18:03:10 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_exception(int number)
{
	char	*str;

	if (number == 0)
		str = ft_strdup("0");
	else
		str = ft_strdup("-2147483648");
	return (str);
}

void		ft_itoa2(int number, char **str, int negative, size_t i)
{
	while (number)
	{
		(*str)[i] = (number) % 10 + '0';
		number = number / 10;
		i++;
	}
	if (negative)
	{
		(*str)[i] = '-';
		i++;
	}
	(*str)[i] = 0;
}

char		*ft_itoa(int number)
{
	int		number2;
	int		negative;
	size_t	size_str;
	char	*str_number;

	size_str = 0;
	negative = 0;
	if (number == 0 || number == -2147483648)
		return (ft_exception(number));
	if (number < 0 && ++negative)
		number = -number;
	number2 = number;
	while (number)
	{
		number = number / 10;
		size_str++;
	}
	str_number = malloc(sizeof(char) * (size_str + 1));
	if (!str_number)
		return (0);
	ft_itoa2(number2, &str_number, negative, 0);
	return (ft_strrev(str_number));
}
