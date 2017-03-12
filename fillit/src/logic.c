/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:44:32 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/03 06:27:39 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tetri.h>

short		is_possible(t_etos *fig, char **field, short x, short y)
{
	short i;
	short j;

	i = -1;
	j = -1;
	if (x < fig->shift)
		return (0);
	while (++i < fig->height)
	{
		j = -1;
		while (++j < fig->width)
		{
			if ((fig->figure)[i][j] == PUST)
				continue ;
			if (field[y + i][x + j - fig->shift] == PUST)
				continue ;
			return (0);
		}
	}
	return (1);
}

void		put_f(t_etos *fig, char **field, short x, short y)
{
	short i;
	short j;

	i = -1;
	j = -1;
	while (++i < fig->height)
	{
		j = -1;
		while (++j < fig->width)
		{
			if ((fig->figure)[i][j] == PUST)
				continue ;
			field[y + i][x + j - fig->shift] = (fig->figure)[i][j];
		}
	}
}

void		erase_f(t_etos *fig, char **field, short x, short y)
{
	short i;
	short j;

	i = -1;
	j = -1;
	while (++i < fig->height)
	{
		j = -1;
		while (++j < fig->width)
		{
			if ((fig->figure)[i][j] == PUST)
				continue ;
			field[y + i][x + j - fig->shift] = PUST;
		}
	}
}

short		move_cursor(short *i, short *j, char **field, short size)
{
	while (*j < size && field[*i][*j] != PUST)
		(*j)++;
	if (*j < size)
		return (1);
	(*i)++;
	while (*i < size)
	{
		*j = -1;
		while (++(*j) < size && field[*i][*j] != PUST)
			;
		if (*j < size)
			return (1);
		(*i)++;
	}
	return (0);
}

short		fillit(char **field, t_etos *figs, short size)
{
	short x;
	short y;

	if (!(figs->figure))
		return (1);
	x = 0;
	y = 0;
	while (move_cursor(&y, &x, field, size))
	{
		if (y + figs->height > size)
			return (0);
		if (x + figs->width - figs->shift > size
			|| !is_possible(figs, field, x, y))
		{
			x++;
			continue;
		}
		put_f(figs, field, x, y);
		if (fillit(field, figs + 1, size))
			return (1);
		erase_f(figs, field, x, y);
		x++;
	}
	return (0);
}
