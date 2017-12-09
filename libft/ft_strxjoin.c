/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:09:23 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/12/09 12:52:16 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		free_something(char *s1, char *s2, size_t x)
{
	if (x == 1 || x == 3)
	{
		free(s1);
		s1 = NULL;
	}
	if (x == 2 || x == 3)
	{	
		free(s2);
		s2 = NULL;
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
