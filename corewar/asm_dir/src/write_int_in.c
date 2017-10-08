/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 15:22:01 by omartyno          #+#    #+#             */
/*   Updated: 2017/03/21 00:06:16 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asmblr.h"

void	write_int_in(int fd, int wr, t_bool small)
{
	int		j;
	char	*to_wr;
	char	*now;

	to_wr = (char *)malloc(sizeof(char) * ((small ? 2 : 4)));
	now = (char *)(&wr);
	now += ((small) ? 1 : 3);
	j = 0;
	while (j++ < ((small) ? 2 : 4))
	{
		to_wr[j - 1] = *now;
		now--;
	}
	write(fd, to_wr, (small) ? 2 : 4);
	free(to_wr);
}
