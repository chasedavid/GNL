/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:09:23 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/30 14:45:58 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strxjoin(char const *s1, char const *s2, size_t x)
{
	char *mem;
	size_t size;

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
		if (x = 1)
			free(s1);
		if (x = 2)
			free(s2);
		if (x = 3)
		{
			free(s1);
			free(s2);
		}
		return (mem);
	}
	return (NULL);
}
