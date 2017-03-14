/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:18:16 by aklimchu          #+#    #+#             */
/*   Updated: 2016/11/25 14:03:14 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen(s);
	while (len > -1 && s[len] != (char)c)
		len--;
	if (s[len] == c)
		return (&((char*)s)[len]);
	else
		return (NULL);
}
