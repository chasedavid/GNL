/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 02:31:28 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/12/11 22:46:43 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*str;
	int		fd;
	int		result;
//	int		i = -1;

	if ((fd = open("tests/file2.txt", O_RDONLY)) < 0)
		return (0);
//	while (++i < 15)
	while ((result = get_next_line(fd, &str)))
	{
//		result = get_next_line(fd, &str);
		printf("%s\n", str);
	}
	close(fd);
	return (0);
}
