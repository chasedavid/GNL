/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:09:23 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/12/06 00:08:29 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		free_something(char *s1, char *s2, size_t x)
{
	if (x == 1)
		if (s1)
			free(s1);
	if (x == 2)
		if (s2)
			free(s2);
	if (x == 3)
	{
		if (s1)
			free(s1);
		if (s2)
			free(s2);
	}
}

char		*ft_strxjoin(char *s1, char *s2, size_t x)
{
	char *mem;
	size_t size;

	mem = NULL;
	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		if (!(mem = (char *)malloc((size + 1) * (sizeof(char)))))
			return (NULL);
		if (mem)
		{
			ft_strcpy(mem, (char *)s1);
			ft_strcat(mem, s2);
		}
		free_something(s1, s2, x);
		return (mem);
	}
	return (NULL);
}
