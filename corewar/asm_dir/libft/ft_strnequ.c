/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:22:50 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/24 14:49:39 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strnequ(char const *s1, char const *s2, size_t len)
{
	unsigned int	it;

	if ((!(s1)) || (!(s2)))
		return (0);
	it = 0;
	while (s1[it] && it < (unsigned int)len)
	{
		if ((unsigned char)s1[it] - (unsigned char)s2[it])
			return (0);
		it++;
	}
	return ((((unsigned char)s1[it] - (unsigned char)s2[it])
			&& (it != (unsigned int)len)) ? 0 : 1);
}
