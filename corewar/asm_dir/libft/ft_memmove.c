/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:23:32 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/22 20:22:05 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long i;

	i = 0;
	if (src == dst)
		return (dst);
	if (src > dst)
	{
		while (++i <= (unsigned long)len)
			((unsigned char*)dst)[i - 1] = ((unsigned char*)src)[i - 1];
	}
	else
	{
		while (++i <= (unsigned long)len)
			((unsigned char*)dst)
				[(unsigned long)len - i] = ((unsigned char*)src)
				[(unsigned long)len - i];
	}
	return (dst);
}
