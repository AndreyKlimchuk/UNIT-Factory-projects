/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:30:31 by aklimchu          #+#    #+#             */
/*   Updated: 2017/01/13 15:32:17 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_dlstdel(t_dlist **adlst, void (*del)(void *, size_t))
{
	t_dlist	*temp;

	while (*adlst)
	{
		temp = (*adlst);
		(*adlst) = (*adlst)->next;
		del(temp->content, temp->content_size);
		free(temp);
	}
}
