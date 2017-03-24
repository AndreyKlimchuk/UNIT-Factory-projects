/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:52:52 by aklimchu          #+#    #+#             */
/*   Updated: 2016/11/23 14:17:07 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!little[0])
		return ((char*)big);
	while (big[i])
	{
		while (big[i + j] == little[j] && big[i + j] && little[j])
			j++;
		if (!little[j])
			return (&((char*)big)[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
