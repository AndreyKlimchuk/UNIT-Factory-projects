/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:51:05 by aklimchu          #+#    #+#             */
/*   Updated: 2016/11/27 12:05:49 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*apply_f(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*temp;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	temp = f(lst);
	new->content = ft_memdup(temp->content, temp->content_size);
	new->content_size = temp->content_size;
	new->next = NULL;
	return (new);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*head;
	t_list		*temp;
	t_list		*next;

	head = NULL;
	if (lst)
	{
		next = lst->next;
		if (!(head = apply_f(lst, (*f))))
			return (NULL);
		temp = head;
		lst = next;
		while (lst)
		{
			next = lst->next;
			if (!(temp->next = apply_f(lst, (*f))))
				return (NULL);
			temp = temp->next;
			lst = next;
		}
	}
	return (head);
}
