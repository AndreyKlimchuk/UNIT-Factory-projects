/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 12:31:55 by aklimchu          #+#    #+#             */
/*   Updated: 2017/01/13 12:47:42 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist	*new_node;

	if (!(new_node = (t_dlist*)malloc(sizeof(t_dlist))))
		return (NULL);
	if (!content)
	{
		new_node->content = NULL;
		new_node->content_size = 0;
	}
	else
	{
		if (!(new_node->content = ft_memdup(content, content_size)))
			return (NULL);
		new_node->content_size = content_size;
	}
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
