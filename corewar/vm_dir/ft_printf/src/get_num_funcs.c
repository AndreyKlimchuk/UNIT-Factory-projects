/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 01:26:10 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/29 15:49:56 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

long long			get_num(const char *src)
{
	size_t		i;
	long long	ans;

	i = 0;
	i += count_chars(src, '0');
	ans = 0;
	while (src[i] >= '0' && src[i] <= '9')
	{
		ans = ans * 10 + src[i] - '0';
		if (ans > 797599049187327)
			return (0);
		i++;
	}
	return (ans);
}

long long			get_nns(const char *src, long long n)
{
	size_t		i;
	long long	ans;

	i = 0;
	if (src[i] == '*')
		return (-(n + 1));
	i += count_chars(src, '0');
	ans = 0;
	while (src[i] >= '0' && src[i] <= '9')
	{
		ans = ans * 10 + src[i] - '0';
		if (ans > 797599049187327)
			return (0);
		i++;
	}
	return (ans);
}
