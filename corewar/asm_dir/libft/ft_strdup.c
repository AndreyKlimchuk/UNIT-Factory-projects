/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:30:59 by omartyno          #+#    #+#             */
/*   Updated: 2017/01/08 16:19:02 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char			*dup;
	size_t			i;

	i = 0;
	while (s1[i])
		i++;
	if (!(dup = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = -1;
	while (s1[++i])
		dup[i] = s1[i];
	dup[i] = 0;
	return (dup);
}
