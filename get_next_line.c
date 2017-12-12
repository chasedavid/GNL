/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:22:24 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/12/12 00:59:17 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_line				*ft_new_fd(int fd)
{
	t_line			*new;

	if (!(new = (t_line *)ft_memalloc(sizeof(t_line))))
		return (NULL);
	new->fd = fd;
	new->leftover = (char *)ft_memalloc(BUFF_SIZE + 1);
	new->next = NULL;
	return (new);
}

t_line				*ft_find_fd(int fd, t_line **head)
{
	t_line			*current;

	current = *head;
	if (!(*head))
	{
		*head = ft_new_fd(fd);
		return (*head);
	}
	while (current->fd != fd)
	{
		if (current->next == NULL)
			current->next = ft_new_fd(fd);
		current = current->next;
	}
	return (current);
}

int					leftover_management(t_line *buf, char *tmp, char **line)
{
	if ((tmp = ft_strchr(buf->leftover, '\n')) != NULL)
	{
		*line = ft_strsub(buf->leftover, 0, tmp - buf->leftover);
		buf->leftover = ft_strcpy(buf->leftover, tmp + 1);
		return (1);
	}
	else
		*line = ft_strcpy(*line, buf->leftover);
	ft_strclr(buf->leftover);
	return (0);
}
/*
int					line_management(char **line, char *buffer, int ret, tmp)
{
	
}*/

int					get_next_line(const int fd, char **line)
{
	static t_line	*head;
	t_line			*buf;
	char			buffer[BUFF_SIZE + 1];
	int				ret;
	char			*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = ft_strnew(BUFF_SIZE);
	tmp = NULL;
	buf = ft_find_fd(fd, &head);
	ft_bzero(buffer, BUFF_SIZE + 1);
	if (buf->leftover[0] && (leftover_management(buf, tmp, line) == 1))
		return (1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0 )
	{
		if (ret < BUFF_SIZE)
			buffer[ret] = '\0';
		if ((tmp = ft_strchr(buffer, '\n')) == NULL)
			*line = ft_strxjoin(*line, buffer, 1);
		else
			break ;
	}
	if (ret < 0)
		return (ret);
	if (tmp)
	{
		*line = ft_strxjoin(*line, ft_strsub(buffer, 0, tmp - (buffer)), 3);
		buf->leftover = ft_strcpy(buf->leftover, tmp + 1);
	}
	return ((!(ret) && !(buf->leftover[0]) && !(*line[0])) ? 0 : 1);
}
