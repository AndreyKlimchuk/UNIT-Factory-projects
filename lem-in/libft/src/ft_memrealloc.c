/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 11:49:13 by aklimchu          #+#    #+#             */
/*   Updated: 2017/02/10 13:48:30 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memrealloc(void **ptr, size_t size)
{
	char	*new;
	char	*old;
	size_t	i;

	if (ptr && *ptr)
		old = (char*)(*ptr);
	if (!(new = ft_memalloc(size)))
		return (NULL);
	i = 0;
	if (ptr && *ptr)
	{
		while (old[i] && i < size)
		{
			new[i] = old[i];
			i++;
		}
		if (i < size)
			new[i] = old[i];
		free(*ptr);
	}
	return (new);
}
