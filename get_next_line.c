/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:22:24 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/12/01 08:55:28 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_line				*ft_new_fd(int fd)
{
	t_line			*new;

	if (!(new = ft_memalloc(sizeof(t_line))))
		return (NULL);
	new->fd = fd;
	new->content = ft_memalloc(BUF_SIZE + 1);
	new->leftover = ft_memalloc(BUF_SIZE + 1);
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

int					get_next_line(const int fd, char **line)
{
	static t_line	*head;
	t_line			*buffer;
	int				ret;
	char			*tmp;

	if (fd < 0 || !(*line)) 
		return (-1);
	*line = NULL;
	buffer = ft_find_fd(fd, head);
//function call in case you have leftovers
	if (buffer->leftover)
	{
		if ((tmp = ft_strchar(buffer->leftover, '\n')) != NULL)
		{
			*line = ft_strsub(buffer->leftover, 0, ft_strchr(buffer->leftover, '\n'));
			buffer->leftover = tmp + 1;
		}
		else
		{
			*line = ft_strsub(buffer->leftover, 0, ft_strlen(buffer->leftover));
			buffer->leftover = 0;
		}
	}
//function call do do if you don't need to use leftovers
	while((ret = read(fd, buffer->content, BUF_SIZE)))
	{
		while ((tmp = ft_strchar(buffer->content, '\n')) == NULL)
			*line = ft_strxjoin(*line, buffer->content, 1);
	}
	*line = ft_strxjoin(*line, ft_strsub(buffer->content, 0, tmp - &(buffer->content)), 3);
		 
	buffer->leftover = tmp + 1;
//check return value to see see if done or if we need to read again 
	return (1);
	
	return (0);	
}
