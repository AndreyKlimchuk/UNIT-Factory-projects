/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:05:05 by aklimchu          #+#    #+#             */
/*   Updated: 2016/11/22 18:37:12 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;

	cs1 = (unsigned char*)s1;
	cs2 = (unsigned char*)s2;
	while (n--)
	{
		if (*cs1 != *cs2)
			return (*cs1 - *cs2);
		else
		{
			cs1++;
			cs2++;
		}
	}
	return (0);
}
