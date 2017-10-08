/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:55:43 by omartyno          #+#    #+#             */
/*   Updated: 2017/01/20 19:32:45 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*skip_shit(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\f')
		i++;
	if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-' && str[i + 1] >= '0'
											&& str[i + 1] <= '9'))
		return ((char *)&str[i]);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	char	*p;
	size_t	i;
	int		num;

	if (!(p = skip_shit(str)))
		return (0);
	num = 0;
	i = (*p == '-') ? 0 : -1;
	while (p[++i] >= '0' && p[i] <= '9')
		num = num * 10 + (int)p[i] - (int)'0';
	return ((*p == '-') ? -num : num);
}
