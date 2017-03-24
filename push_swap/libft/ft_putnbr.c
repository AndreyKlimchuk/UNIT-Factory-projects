/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:08:47 by aklimchu          #+#    #+#             */
/*   Updated: 2016/11/25 17:40:33 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putnbr(int n)
{
	unsigned int	num;
	int				buff[10];
	int				i;

	if (!n)
		write(1, "0", 1);
	else
	{
		if (n < 0)
			write(1, "-", 1);
		num = (n < 0) ? -n : n;
		i = 0;
		while (num)
		{
			buff[i++] = num % 10;
			num /= 10;
		}
		while (--i >= 0)
			ft_putchar(buff[i] + '0');
	}
}
