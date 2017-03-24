/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 10:36:06 by aklimchu          #+#    #+#             */
/*   Updated: 2016/11/26 11:39:54 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memdup(void const *src, size_t size)
{
	char	*dst;
	size_t	i;

	if (!size || !src || !(dst = (char*)malloc(size)))
		return (NULL);
	i = -1;
	while (++i < size)
		dst[i] = ((char*)src)[i];
	return ((void*)dst);
}
