/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 17:09:02 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/31 17:28:15 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_putbits(void *d, size_t ds)
{
	unsigned char	*w;
	unsigned char	*pb;
	size_t			i;
	short			zed;

	w = (unsigned char *)d;
	pb = (unsigned char *)malloc(8 * ds + ds - 1);
	i = 0;
	w += ds - 1;
	while (ds--)
	{
		zed = 8;
		while (zed--)
			pb[i++] = (*w & 1 << zed) ? '1' : '0';
		if (ds)
			pb[i++] = ' ';
		w--;
	}
	return ((char *)pb);
}
