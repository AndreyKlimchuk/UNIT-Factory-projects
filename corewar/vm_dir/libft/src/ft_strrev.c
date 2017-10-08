/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 17:36:42 by aklimchu          #+#    #+#             */
/*   Updated: 2017/03/26 08:45:23 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrev(char *str)
{
	int				i;
	int				size;
	char			temp;

	if (str)
	{
		i = -1;
		size = ft_strlen(str);
		while (++i < --size)
		{
			temp = str[i];
			str[i] = str[size];
			str[size] = temp;
		}
	}
	return (str);
}
