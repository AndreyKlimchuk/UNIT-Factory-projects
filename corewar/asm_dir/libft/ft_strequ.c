/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:53:57 by omartyno          #+#    #+#             */
/*   Updated: 2017/02/28 19:35:04 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strequ(char const *s1, char const *s2)
{
	size_t	it;

	if ((!(s1)) || (!(s2)))
		return (0);
	it = 0;
	while (s1[it])
	{
		if ((unsigned char)s1[it] - (unsigned char)s2[it])
			return (0);
		it++;
	}
	return (s2[it] ? 0 : 1);
}
