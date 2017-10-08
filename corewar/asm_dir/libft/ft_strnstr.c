/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:06:32 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/22 21:25:59 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int	slen(const char *s)
{
	int	len;

	len = -1;
	while (s[++len])
		;
	return (len);
}

char		*ft_strnstr(const char *big, const char *lil, size_t len)
{
	int i;
	int j;

	if (!slen(lil))
		return ((char *)big);
	i = 0;
	while (big[i + slen(lil) - 1] && big[i] && (i + slen(lil) - 1) < (int)len)
	{
		if (big[i] == *lil)
		{
			j = 0;
			while (big[i + j] == lil[j] && big[i + j] && i + j < (int)len)
				j++;
			if (j == slen(lil))
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}
