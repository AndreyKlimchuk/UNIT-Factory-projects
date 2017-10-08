/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:16:59 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/24 15:51:16 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	str_size(char const *s)
{
	unsigned int	size;
	unsigned int	i;

	i = 0;
	size = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	while (s[i + size])
		size++;
	if (!size)
		return (0);
	size--;
	while ((s[i + size] == ' ' || s[i + size] == '\n' || s[i + size] == '\t')
			&& ((size + i) > 0))
		size--;
	return (size + 1);
}

char				*ft_strtrim(char const *s)
{
	unsigned int	sz;
	unsigned int	size;
	unsigned int	it;
	char			*new;

	if (!(s))
		return (0);
	size = str_size(s);
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	it = 0;
	while ((s[it] == ' ' || s[it] == '\n' || s[it] == '\t') && s[it])
		it++;
	sz = 0;
	while (sz < size)
	{
		new[sz] = s[sz + it];
		sz++;
	}
	new[sz] = 0;
	return (new);
}
