/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:01:55 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/23 19:06:18 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*mew;
	t_list	*rrr;

	mew = lst;
	while (mew)
	{
		rrr = mew->next;
		(*f)(mew);
		mew = rrr;
	}
}
