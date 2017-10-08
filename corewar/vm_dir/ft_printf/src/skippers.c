/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skippers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 21:37:55 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/29 21:01:57 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

size_t				count_chars(const char *src, char ch)
{
	size_t	i;

	i = 0;
	while (src[i] == ch)
		i++;
	return (i);
}

size_t				skip_num(const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] >= '0' && src[i] <= '9')
		i++;
	return (i);
}

size_t				skip_snn(const char *src)
{
	size_t	i;

	i = 0;
	if (src[i] == '*')
		return (1);
	while (src[i] >= '0' && src[i] <= '9')
		i++;
	return (i);
}
