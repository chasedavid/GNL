/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 02:31:28 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/12/09 21:47:01 by envy-15          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*str;
	int		fd, fd1;
	int		result;

	if ((fd = open("tests/file.txt", O_RDONLY)) < 0)
		return (0);

	while ((result = get_next_line(fd, &str)))
	{
		printf("%s\n", str);
	}
	if ((fd1 = open("tests/file1.txt", O_RDONLY)) < 0)
		return (0);	close(fd);
	while ((result = get_next_line(fd, &str)))
		printf("%s\n", str);
	close(fd1); 
	return (0);
}
