/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:08:53 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/23 21:07:48 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	i;

	i = -1;
	while (++i < (unsigned long)n)
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
	return (dst);
}
