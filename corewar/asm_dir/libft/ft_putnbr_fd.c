/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 20:54:22 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/21 20:55:07 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static short int	num_s(int n)
{
	short int	number_size;

	number_size = 0;
	while (n)
	{
		number_size++;
		n /= 10;
	}
	return (number_size);
}

static int			pw(int n1, int n2)
{
	int rt;

	if (n2 <= 0)
		return (1);
	rt = 1;
	while (n2--)
		rt *= n1;
	return (rt);
}

void				ft_putnbr_fd(int n, int fd)
{
	short int	str_s;
	short int	i;
	char		to_put;

	str_s = num_s(n);
	i = 0;
	if (n < 0 && ++i)
		write(fd, "-", 1);
	if (n == 0 && ++i)
		write(fd, "0", 1);
	while (--str_s >= 0)
	{
		to_put = (n < 0) ? '0' - (n / pw(10, str_s)) % 10 :
								'0' + (n / pw(10, str_s)) % 10;
		write(fd, &to_put, 1);
	}
}
