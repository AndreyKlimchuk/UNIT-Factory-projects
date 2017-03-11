/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 16:48:08 by aklimchu          #+#    #+#             */
/*   Updated: 2017/01/12 17:00:40 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_atoll(const char *str)
{
	size_t		i;
	long long	num;
	int			flag;

	i = 0;
	num = 0;
	flag = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
	|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '
	|| (str[i] == '+' && ft_isdigit(str[i + 1])))
		i++;
	if (str[i] == '-')
	{
		i++;
		flag = 1;
	}
	while (ft_isdigit(str[i]))
		num = 10 * num + (long long)str[i++] - '0';
	if (flag)
		num *= -1;
	return (num);
}
