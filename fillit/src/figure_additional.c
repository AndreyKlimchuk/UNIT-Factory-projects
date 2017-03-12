/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_additional.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 05:46:44 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/03 06:53:29 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tetri.h>

int				get_width(char ***fig)
{
	int i;
	int j;
	int jmin;
	int jmax;

	j = -1;
	jmin = -1;
	jmax = -1;
	while (++j < 4 && jmin == -1)
	{
		i = -1;
		while (++i < 4 && jmin == -1)
			if ((*fig)[i][j] != PUST)
				jmin = j;
	}
	j = 4;
	while (j-- && jmax == -1)
	{
		i = 4;
		while (i-- && jmax == -1)
			if ((*fig)[i][j] != PUST)
				jmax = j;
	}
	return (jmax - jmin + 1);
}

int				get_height(char ***fig)
{
	int i;
	int j;
	int imin;
	int imax;

	i = -1;
	imin = -1;
	imax = -1;
	while (++i < 4 && imin == -1)
	{
		j = -1;
		while (++j < 4 && imin == -1)
			if ((*fig)[i][j] != PUST)
				imin = i;
	}
	i = 4;
	while (i-- && imax == -1)
	{
		j = 4;
		while (j-- && imax == -1)
			if ((*fig)[i][j] != PUST)
				imax = i;
	}
	return (imax - imin + 1);
}

int				get_shift(char **fig, int width)
{
	int j;
	int s;

	j = -1;
	s = 0;
	while (++j < width && fig[0][j] == PUST)
		s++;
	return (s);
}

void			fill_fig(short h, short w, short n, t_etos *figure)
{
	figure->height = h;
	figure->width = w;
	figure->num = n;
}
