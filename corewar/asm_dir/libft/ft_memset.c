/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:53:26 by omartyno          #+#    #+#             */
/*   Updated: 2017/03/24 18:38:17 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long	count;

	count = 0;
	while (count < (unsigned long)len)
		*((unsigned char*)(b + count++)) = (unsigned char)c;
	return (b);
}
