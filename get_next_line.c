/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:22:24 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/12/08 15:05:36 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_line				*ft_new_fd(int fd)
{
	t_line			*new;

	if (!(new = (t_line *)ft_memalloc(sizeof(t_line))))
		return (NULL);
	new->fd = fd;
	new->leftover = (char *)ft_memalloc(BUF_SIZE + 1);
	new->next = NULL;
	return (new);
}

t_line				*ft_find_fd(int fd, t_line *head)
{
	t_line			*current;

	current = head;
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

int					get_next_line(const int fd, char **line)
{
	static t_line	*head;
	t_line			*buf;
	char			str[BUF_SIZE + 1];
	int				ret;
	char			*tmp;

	tmp = NULL;
	if (!(head))	
		head = ft_new_fd(fd);
	if (fd < 0) 
		return (-1);
	str[BUF_SIZE] = '\0';
	buf = ft_find_fd(fd, head);
	if (buf->leftover[0])
		if (leftover_management(buf, tmp, line) == 1)
			return (1);
	while((ret = read(fd, str, BUF_SIZE)))
		if ((tmp = ft_strchr(str, '\n')) == NULL)
			*line = ft_strxjoin(*line, str, 0);
		else
			break ;
		*line = ft_strxjoin(*line, ft_strsub(str, 0, tmp - (str)), 3);
	buf->leftover = ft_strcpy(buf->leftover, tmp + 1);
	return ((ret) ? 1 : 0);
}
