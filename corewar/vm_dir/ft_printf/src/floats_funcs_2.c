/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats_funcs_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 21:41:10 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/29 11:39:30 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

unsigned long long	ten_max(void)
{
	unsigned long long	max;
	unsigned long long	ret;

	max = ULLONG_MAX;
	max /= 10;
	ret = 1000000000000000000;
	while (ret < max)
		ret *= 10;
	return (ret);
}

long double			dec_part(long double x)
{
	if (x > ULLONG_MAX)
		return (0);
	x -= (unsigned long long)x;
	return (x);
}

int					plus_plus(char *s)
{
	size_t l;

	if (!(*s))
		return (1);
	l = ft_strlen(s);
	while (l)
	{
		(s[--l])++;
		if (s[l] == ('9' + 1))
			s[l] = '0';
		else
			break ;
	}
	if (s[l] == '0')
		return (1);
	return (0);
}

long double			after_point(long double x, long long prec, char *s)
{
	int			i;
	long long	int_x;

	i = -1;
	while (++i < prec)
	{
		x *= 10;
		int_x = (long long)(x);
		s[i] = MOD(int_x) + '0';
		x -= int_x;
	}
	return (x);
}

int					get_rank(long double *x, int base, int del)
{
	int	i;

	i = 0;
	if (!(*x))
		return (i);
	*x = (*x < 0) ? -(*x) : *x;
	while (*x < base)
	{
		i--;
		*x *= del;
	}
	while (*x >= base)
	{
		i++;
		*x /= del;
	}
	return (i);
}
