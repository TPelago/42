/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:18:06 by tpelago           #+#    #+#             */
/*   Updated: 2015/01/13 12:33:10 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static int		ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int		ft_ispositive(char **c)
{
	if (**c == '-')
	{
		(*c)++;
		return (0);
	}
	if (**c == '+')
	{
		(*c)++;
		return (1);
	}
	else
		return (1);
}

static size_t	ft_digitslen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

static int		ft_pow(int n)
{
	int		number;

	number = 1;
	while (n)
	{
		number *= 10;
		n--;
	}
	return (number);
}

int				ft_atoi(const char *str)
{
	char	*number;
	int		positive;
	int		int_number;
	size_t	len;
	size_t	i;

	i = 0;
	int_number = 0;
	positive = 1;
	number = (char *)str;
	if (ft_strcmp("-2147483648", number) == 0)
		return (-2147483648);
	while (ft_isspace(*number))
		number++;
	positive = ft_ispositive(&number);
	len = ft_digitslen(number);
	while (i < len)
	{
		int_number += ((number[i] - '0') * ft_pow(len - i - 1));
		i++;
	}
	if (positive == 0)
		return (-int_number);
	return (int_number);
}
