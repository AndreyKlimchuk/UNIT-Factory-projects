/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:20:42 by aklimchu          #+#    #+#             */
/*   Updated: 2016/11/25 13:55:08 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cdst;
	char	*csrc;

	cdst = (char*)dst;
	csrc = (char*)src;
	if (cdst != csrc)
	{
		if (csrc < cdst)
			while (len--)
				cdst[len] = csrc[len];
		else
			while (len--)
				*cdst++ = *csrc++;
	}
	return (dst);
}
