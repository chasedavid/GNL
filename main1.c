/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 02:31:28 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/12/11 17:43:55 by cfarnswo         ###   ########.fr       */
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

/*	while ((result = get_next_line(fd, &str)))
	{
		printf("%s\n", str);
	}
	close(fd);*/
	if ((fd1 = open("tests/file2.txt", O_RDONLY)) < 0)
		return (0);
	while ((result = get_next_line(fd1, &str)))
		printf("%s\n", str);
	close(fd1); 
	return (0);
}
