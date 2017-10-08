/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:47:17 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/22 13:53:30 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned long	d_len;
	unsigned long	s_len;
	unsigned long	i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	d_len = i;
	i = 0;
	while (src[i] != '\0')
		i++;
	s_len = i;
	i = 0;
	while (src[i] != '\0' && ((d_len + i) < (size - 1)))
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return ((size_t)(s_len + ((d_len < size) ? d_len : size)));
}
