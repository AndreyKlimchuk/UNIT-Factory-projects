/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:20:25 by aklimchu          #+#    #+#             */
/*   Updated: 2016/11/23 14:38:22 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!little[0])
		return ((char*)big);
	while (big[i] && i < len)
	{
		while (big[i + j] == little[j] && (i + j) < len
		&& big[i + j] && little[j])
			j++;
		if (!little[j])
			return (&((char*)big)[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
