/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_placevalues.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 09:46:36 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/10/17 10:24:01 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_num_placevalues(int n)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		++i;
		n = -n;
	}
	while (n / 10 >= 1 || n / 10 <= -1)
	{
		++i;
		n /= 10;
	}
	return (i);
}
