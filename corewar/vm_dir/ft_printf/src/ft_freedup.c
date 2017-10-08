/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freedup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:16:08 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/23 03:18:54 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_freedup(char **s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	if (*s1)
		my_free((void **)s1);
	*s1 = (char *)malloc(ft_strlen(s2) + 1);
	while (s2[i])
		(*s1)[i] = s2[i];
	(*s1)[i] = 0;
	return (*s1);
}
