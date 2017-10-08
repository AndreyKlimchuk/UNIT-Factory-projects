/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 20:17:44 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/21 20:44:37 by omartyno         ###   ########.fr       */
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

void				ft_putnbr(int n)
{
	short int	str_s;
	short int	i;
	char		to_put;

	str_s = num_s(n);
	i = 0;
	if (n < 0 && ++i)
		write(1, "-", 1);
	if (n == 0 && ++i)
		write(1, "0", 1);
	while (--str_s >= 0)
	{
		to_put = (n < 0) ? '0' - (n / pw(10, str_s)) % 10 :
								'0' + (n / pw(10, str_s)) % 10;
		write(1, &to_put, 1);
	}
}
