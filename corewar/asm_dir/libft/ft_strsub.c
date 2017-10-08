/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:29:41 by omartyno          #+#    #+#             */
/*   Updated: 2017/03/14 17:51:15 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	it;

	if (!(s))
		return (0);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == 0)
		return (new);
	it = 0;
	while (it < len)
	{
		new[it] = s[start + it];
		it++;
	}
	new[it] = 0;
	return (new);
}
