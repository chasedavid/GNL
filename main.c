/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 02:31:28 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/29 02:32:35 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*str;
	int		fd;
	int		result;

	if ((fd = open("tests/file.txt", O_RDONLY)) < 0)
		return (0);
	while ((result = get_next_line(fd, &str)) != 0)
	{
		printf("%s\n", str);
		free(str);
	}
	close(fd);
	return (0);
}
