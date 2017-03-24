/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:35:05 by aklimchu          #+#    #+#             */
/*   Updated: 2017/01/23 09:52:44 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	size_t	i;
	int		num;
	int		flag;

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
		num = 10 * num + (int)str[i++] - '0';
	if (flag)
		num *= -1;
	return (num);
}
