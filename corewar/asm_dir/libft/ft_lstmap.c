/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:06:46 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/24 15:47:15 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static void		*memicpy(void *dst, const void *src, size_t n)
{
	unsigned long	i;

	i = -1;
	while (++i < (unsigned long)n)
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
	return (dst);
}

static t_list	*do_f(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*work;

	new = malloc(sizeof(t_list));
	work = (*f)(lst);
	new->content = malloc(work->content_size);
	memicpy(new->content, work->content, work->content_size);
	new->content_size = work->content_size;
	new->next = 0;
	return (new);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *anew;
	t_list *now;
	t_list *nxt;
	t_list *now2;
	t_list *nxt2;

	if (!(lst))
		return (0);
	now = lst;
	nxt = now->next;
	anew = do_f(now, (*f));
	now2 = anew;
	now = nxt;
	while (now)
	{
		nxt = now->next;
		nxt2 = do_f(now, (*f));
		now = nxt;
		now2->next = nxt2;
		now2 = nxt2;
	}
	return (anew);
}
