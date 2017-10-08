/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:35:03 by omartyno          #+#    #+#             */
/*   Updated: 2017/01/27 17:21:47 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*mew_next;
	t_list	*mew_cur;

	mew_cur = *alst;
	mew_next = mew_cur->next;
	del(mew_cur->content, mew_cur->content_size);
	mew_cur = mew_next;
	while (mew_cur)
	{
		mew_next = mew_cur->next;
		del(mew_cur->content, mew_cur->content_size);
		free(mew_cur);
		mew_cur = mew_next;
	}
	free(*alst);
	*alst = 0;
}
