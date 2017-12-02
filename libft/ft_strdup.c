/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:28:01 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/12/02 15:07:42 by envy-15          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char		*dup;
	char		*temp;
	size_t		len;

	len = ft_strlen(s1);
	if(!(dup = (char*)malloc((len + 1))))
		return (NULL);
	temp = dup;
	while (*s1)
		*temp++ = *s1++;
	*temp = '\0';
	return (dup);
}
