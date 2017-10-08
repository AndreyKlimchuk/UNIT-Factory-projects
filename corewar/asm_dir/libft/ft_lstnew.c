/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:56:19 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/23 19:42:01 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*mew;
	size_t	count;

	if (!(mew = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (!content)
		mew->content = 0;
	else
	{
		mew->content = malloc(content_size);
		count = 0;
		while (count < content_size)
		{
			((char *)(mew->content))[count] = ((char *)(content))[count];
			count++;
		}
	}
	mew->content_size = (content) ? content_size : 0;
	mew->next = 0;
	return (mew);
}
