/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 19:52:02 by tpelago           #+#    #+#             */
/*   Updated: 2016/04/20 19:53:04 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 8

typedef struct		s_line
{
	char			buff[BUFF_SIZE + 1];
	int				status;
	int				fd;
	struct s_line	*next;
}					t_line;

int					get_next_line(int const fd, char **line);
#endif
