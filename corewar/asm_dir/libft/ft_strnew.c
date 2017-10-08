/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:10:50 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/24 14:37:23 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char			*new;
	size_t			counter;

	if (!(new = (char *)malloc(size + 1)))
		return (0);
	counter = 0;
	while (counter <= size)
	{
		new[counter] = 0;
		counter++;
	}
	return (new);
}
