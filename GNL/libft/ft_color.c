/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/13 16:19:21 by tpelago           #+#    #+#             */
/*   Updated: 2015/10/17 14:12:06 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_valid_code_and_mode(char *code, int mode)
{
	if (mode == 0 || mode == 1 || mode == 4 || mode == 7)
		;
	else
		return (0);
	if (ft_strequ(code, BLACK_CODE) || ft_strequ(code, BLUE_CODE))
		return (1);
	if (ft_strequ(code, BROWN_CODE) || ft_strequ(code, CYAN_CODE))
		return (1);
	if (ft_strequ(code, DARKGREY_CODE) || ft_strequ(code, GREEN_CODE))
		return (1);
	if (ft_strequ(code, LIGHTBLUE_CODE) || ft_strequ(code, WHITE_CODE))
		return (1);
	if (ft_strequ(code, LIGHTPURPLE_CODE) || ft_strequ(code, YELLOW_CODE))
		return (1);
	if (ft_strequ(code, LIGHTGREY_CODE) || ft_strequ(code, LIGHTCYAN_CODE))
		return (1);
	if (ft_strequ(code, LIGHTRED_CODE) || ft_strequ(code, RED_CODE))
		return (1);
	if (ft_strequ(code, PURPLE_CODE) || ft_strequ(code, GREY_CODE))
		return (1);
	return (0);
}

void		ft_color(char *color_code, int mode)
{
	if (!color_code || ft_valid_code_and_mode(color_code, mode) == 0)
		ft_putstr("\033[0m");
	else
	{
		ft_putchar(color_code[0]);
		ft_putchar(color_code[1]);
		ft_putchar(mode + '0');
		ft_putstr(color_code + 3);
	}
}
