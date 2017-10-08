/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:17:39 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/22 12:22:49 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		*((unsigned char*)dst++) = *((unsigned char*)src++);
		if (*((unsigned char*)src) == (unsigned char)c)
		{
			*((unsigned char*)dst++) = *((unsigned char*)src);
			return (dst);
		}
	}
	return (NULL);
}
