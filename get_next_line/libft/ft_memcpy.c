/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:42:36 by aklimchu          #+#    #+#             */
/*   Updated: 2016/11/25 14:13:17 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*csrc;
	char	*cdst;

	csrc = (char*)src;
	cdst = (char*)dst;
	while (n > 0)
	{
		*cdst++ = *csrc++;
		n--;
	}
	return (dst);
}
