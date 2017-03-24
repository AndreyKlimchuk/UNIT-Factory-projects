/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:34:36 by aklimchu          #+#    #+#             */
/*   Updated: 2016/11/25 13:57:48 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs;
	unsigned char	cp;

	cs = (unsigned char*)s;
	cp = c;
	while (n-- && *cs != cp && *cs)
		cs++;
	if (*cs != cp)
		cs = 0;
	return ((void*)cs);
}
