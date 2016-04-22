/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 11:46:49 by tpelago           #+#    #+#             */
/*   Updated: 2015/12/16 12:25:00 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static	char	*ft_stock_hexa(int nb, int fake_nb)
{
	static char hexa_nb[8];
	static	int i = 0;

	if (nb < 16)
	{
		if (nb < 10)
			hexa_nb[i] = nb + '0';
		else
			hexa_nb[i] = 'a' - 10 + nb % 16;
		i++;
	}
	else
	{
		ft_stock_hexa(nb / 16, fake_nb - 1);
		ft_stock_hexa(nb % 16, fake_nb - 1);
	}
	if (nb == fake_nb)
	{
		while (i < 8)
			hexa_nb[i++] = '0';
		i = 0;
	}
	return (hexa_nb);
}

static	void	print_hexa_value(int nb, int padding_only)
{
	char	*hexa_nb;

	if (padding_only == 1)
		write(1, &"          ", 10);
	else
	{
		hexa_nb = ft_stock_hexa(nb, nb);
		if (padding_only == 2)
			write(1, " ", 1);
		write(1, hexa_nb, 4);
		write(1, &" ", 1);
		write(1, hexa_nb + 4, 4);
	}
}

static	void	print_text(char **str, int char_nb)
{
	int		i;

	i = 0;
	if (!str || !*str)
		return ;
	write(1, &" ", 1);
	i = char_nb + 4;
	if (i > 16)
		i = i % 16;
	if (i == 0)
		i = 16;
	while (i--)
	{
		if (**str < 32 || **str >= 127)
			write(1, &".", 1);
		else
			write(1, &(**str), 1);
		(*str)++;
	}
	write(1, &"\n", 1);
}

void			ft_print_memory(const void *addr, size_t size)
{
	int		*tab;
	char	*str;
	size_t	i[2];

	i[0] = 0;
	str = (char *)addr;
	tab = (int *)addr;
	while (i[0] < size)
	{
		if (i[0] % (4 * sizeof(int)) == 0)
			print_hexa_value(*tab, 0);
		else
			print_hexa_value(*tab, 2);
		if ((TXEN % (4 * SOF(INT)) == 0 && TXEN) || (TXEN >= size))
		{
			i[1] = i[0];
			while (((i[0] + SOF(INT)) % (4 * SOF(INT))) && (i[0] += SOF(INT)))
				print_hexa_value(42, 1);
			print_text(&str, i[1]);
		}
		tab += 1;
		i[0] += sizeof(int);
	}
}
