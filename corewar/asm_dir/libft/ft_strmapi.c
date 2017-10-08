/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:37:49 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/24 14:47:29 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		new[iter] = (*f)(iter, s[iter]);
		iter++;
	}
	new[iter] = 0;
	return (new);
}
