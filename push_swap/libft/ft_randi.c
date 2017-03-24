/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:38:53 by aklimchu          #+#    #+#             */
/*   Updated: 2017/02/06 11:15:33 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_randi(int min, int max)
{
	static time_t	sec;

	if (!sec)
	{
		sec = time(0);
		srand(sec);
	}
	return (rand() % (max - min + 1) + min);
}
