/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 19:44:14 by tpelago           #+#    #+#             */
/*   Updated: 2016/04/22 18:22:14 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_create_buff(char *buff, int j)
{
	char	*tmp;
	int		size;

	size = ft_strlen((const char *)buff);
	tmp = (char *)malloc(sizeof(char) * (size - j));
	if (tmp == NULL)
		return (-1);
	ft_strcpy(tmp, (const char *)(buff + j + 1));
	ft_bzero(buff, size);
	ft_strcpy(buff, tmp);
	bzero(tmp, size - j);
	free(tmp);
	return (1);
}

int		ft_retzero(char *line)
{
	char	*copy;

	if (line[0] == 0)
		return (0);
	copy = ft_strdup(line);
	copy[ft_strlen(copy)] = '\n';
	return (ft_create_buff(copy, 0));
}

int		ft_buff(char *buff, char **line)
{
	int		j;
	char	*s2;

	j = 0;
	while (buff[j] != '\n' && buff[j] != 0)
		j++;
	s2 = (char *)malloc(sizeof(char) * (j + ft_strlen(*line) + 1));
	if (s2 == NULL)
		return (-1);
	ft_strcpy(s2, *line);
	ft_strncat(s2, buff, j);
	ft_bzero(*line, ft_strlen(*line));
	free(*line);
	*line = s2;
	if (buff[j] == '\n')
		return (ft_create_buff(buff, j));
	else
	{
		ft_bzero(buff, ft_strlen(buff));
		return (2);
	}
}

t_line	*get_elem(int fd, t_line **begin_list)
{
	t_line *tmp;
	t_line *elem;

	tmp = *begin_list;
	if (tmp != NULL)
	{
		while (tmp)
		{
			if (tmp->fd == fd)
				return (tmp);
			tmp = tmp->next;
		}
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
	}
	if ((elem = malloc(sizeof(t_line))) == NULL)
		return (elem);
	bzero(elem, sizeof(t_line));
	elem->fd = fd;
	if (*begin_list)
		tmp->next = elem;
	else
		tmp = elem;
	return (elem);
}

int		get_next_line(int const fd, char **line)
{
	static t_line		*begin_list = NULL;
	int					ret;
	t_line				*elem;

	if (begin_list == NULL)
		begin_list = get_elem(fd, &begin_list);
	elem = get_elem(fd, &begin_list);
	if (elem == NULL || line == NULL || BUFF_SIZE < 1)
		return (-1);
	*line = ft_strdup("");
	elem->status = 2;
	while (elem->status == 2)
	{
		if (elem->buff[0] == 0)
		{
			if ((ret = read(fd, elem->buff, BUFF_SIZE)) == -1)
				return (-1);
			if (ret > 0)
				elem->buff[ret] = 0;
			if (ret == 0)
				return (ft_retzero(*line));
		}
		elem->status = ft_buff(elem->buff, line);
	}
	return (elem->status);
}
