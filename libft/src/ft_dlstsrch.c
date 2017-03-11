/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsrch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:44:52 by aklimchu          #+#    #+#             */
/*   Updated: 2017/01/23 09:53:56 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_dlstsrch(t_dlist *node, void const *content,
					size_t content_size)
{
	while (node)
	{
		if (node->content_size == content_size &&
			!ft_memcmp(node->content, content, content_size))
			return (node);
		node = node->next;
	}
	return (NULL);
}
