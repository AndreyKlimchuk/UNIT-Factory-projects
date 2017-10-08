/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:23:05 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/22 13:26:58 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	while (n--)
	{
		if (*c1 - *c2)
			return ((int)(*c1 - *c2));
		else
		{
			c1++;
			c2++;
		}
	}
	return (0);
}
