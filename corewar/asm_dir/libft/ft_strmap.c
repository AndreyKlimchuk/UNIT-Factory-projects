/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:32:11 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/24 14:46:43 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*new;
	unsigned int	size;
	unsigned int	iter;

	if (!(s))
		return (0);
	size = 0;
	while (s[size])
		size++;
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	iter = 0;
	while (iter < size)
	{
		new[iter] = (*f)(s[iter]);
		iter++;
	}
	new[iter] = 0;
	return (new);
}
