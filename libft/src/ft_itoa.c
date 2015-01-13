/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 15:28:44 by tpelago           #+#    #+#             */
/*   Updated: 2015/01/13 12:40:12 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
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

static char	*strrev(char *str)
{
	char	tmp;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		tmp = str[len - 1];
		str[len - 1] = str[i];
		str[i] = tmp;
		i++;
		len--;
	}
	return (str);
}

char		*init_str(char **str, int *positive, size_t *i)
{
	*i = 0;
	*positive = 1;
	(*str) = malloc(sizeof(char) * 12);
	return (*str);
}

char		*ft_itoa(int number)
{
	int		positive;
	size_t	i;
	char	*str_number;

	init_str(&str_number, &positive, &i);
	if (number == 0 || number == -2147483648)
		return (ft_exception(number));
	if (number < 0)
	{
		number = -number;
		positive = 0;
	}
	while (number)
	{
		str_number[i] = (number) % 10 + '0';
		number = number / 10;
		i++;
	}
	if (!positive)
	{
		str_number[i] = '-';
		i++;
	}
	str_number[i] = 0;
	return (strrev(str_number));
}
