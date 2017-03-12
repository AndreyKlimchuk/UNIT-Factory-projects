/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:11:01 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/03 09:29:30 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tetri.h>

char	**field_size(int size)
{
	int		i;
	int		j;
	char	**field;

	if (!(field = (char **)malloc(sizeof(char *) * size)))
		error("No memory!", 2, 2);
	i = -1;
	while (++i < size)
		field[i] = (char *)malloc(size);
	while (--i >= 0)
	{
		j = -1;
		while (++j < size)
			field[i][j] = PUST;
	}
	return (field);
}

short	count_size(int fig_num)
{
	short size;

	size = 0;
	while (size * size < fig_num * 4)
		size++;
	return (size);
}
