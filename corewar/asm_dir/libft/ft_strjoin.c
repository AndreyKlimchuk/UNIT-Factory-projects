/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:45:47 by omartyno          #+#    #+#             */
/*   Updated: 2017/02/17 19:28:18 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	str_size(char const *s)
{
	size_t	sz;

	sz = 0;
	while (s[sz])
		sz++;
	return (sz);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t			con_size;
	size_t			i1;
	size_t			i2;
	char			*new;

	if (!s1)
		return (0);
	if (!s2)
		return (ft_strdup(s1));
	con_size = str_size(s1) + str_size(s2);
	if (!(new = (char *)malloc(sizeof(char) * (con_size + 1))))
		return (0);
	i1 = -1;
	while (s1[++i1])
		new[i1] = s1[i1];
	i2 = 0;
	while (s2[i2])
		new[i1++] = s2[i2++];
	new[i1] = '\0';
	return (new);
}
