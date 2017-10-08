/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:33:08 by aklimchu          #+#    #+#             */
/*   Updated: 2017/01/13 14:43:54 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd(t_dlist **adlst, t_dlist *new)
{
	if (new)
	{
		if (*adlst)
		{
			new->next = *adlst;
			(*adlst)->prev = new;
			new->prev = NULL;
		}
		*adlst = new;
	}
}
