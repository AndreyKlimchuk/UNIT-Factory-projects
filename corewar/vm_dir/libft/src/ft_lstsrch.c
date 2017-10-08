/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsrch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:40:38 by aklimchu          #+#    #+#             */
/*   Updated: 2017/02/09 12:41:22 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstsrch(t_list *node, void const *content,
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
