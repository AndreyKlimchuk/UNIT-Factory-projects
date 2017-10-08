/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:42:22 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/22 13:44:22 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	unsigned long i;
	unsigned long j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while ((src[j] != '\0') && (j < (unsigned long)nb))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
