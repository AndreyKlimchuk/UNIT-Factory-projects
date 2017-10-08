/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:51:03 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/21 16:54:01 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void			*new;
	unsigned int	it;

	new = malloc(size);
	if (new == 0)
		return (0);
	it = 0;
	while (it < (unsigned int)size)
	{
		(*((unsigned char *)(new + it))) = 0;
		it++;
	}
	return (new);
}
