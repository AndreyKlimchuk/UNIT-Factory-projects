/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:54:26 by aklimchu          #+#    #+#             */
/*   Updated: 2016/11/27 20:19:45 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	unsigned char	cp;

	cp = (unsigned char)c;
	cdst = (unsigned char*)dst;
	csrc = (unsigned char*)src;
	while (n-- && *csrc != cp)
		*cdst++ = *csrc++;
	if (*csrc == cp)
		*cdst++ = *csrc;
	else
		cdst = 0;
	return ((void*)cdst);
}
