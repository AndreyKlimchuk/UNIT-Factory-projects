/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:58:01 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/03 09:30:29 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tetri.h>

char			**one_figure(char *src, short num)
{
	int		i;
	char	**fig;

	if (!(fig = (char **)malloc(sizeof(char *) * 4)))
		error("No memory!", 2, 2);
	i = -1;
	while (++i < 4)
		if (!(fig[i] = (char *)malloc(4)))
			error("No memory!", 2, 2);
	i = -1;
	while (++i < 20)
	{
		if (src[i] == '.')
			fig[i / 5][i % 5] = PUST;
		else if (src[i] == '#')
			fig[i / 5][i % 5] = 'A' + num;
		else if ((src[i] == '\n' && i % 5 != 4) || src[i] != '\n')
			error("error", 1, 1);
	}
	if (src[i] != '\n' && src[i])
		error("error", 1, 1);
	return (fig);
}

static void		find_start(char **fig, int *js, int *is)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (fig[i][j] != PUST && *is == -1)
				*is = i;
			if (fig[j][i] != PUST && *js == -1)
				*js = i;
		}
	}
}

int				smaller(char ***fig, int hgt, int wgt)
{
	char	**new_f;
	int		i;
	int		j;
	int		is;
	int		js;

	if (!(new_f = (char **)malloc(sizeof(char *) * hgt)))
		error("No memory!", 2, 2);
	i = -1;
	while (++i < hgt)
		if (!(new_f[i] = (char *)malloc(sizeof(char) * wgt)))
			error("No memory!", 2, 2);
	is = -1;
	js = -1;
	find_start(*fig, &js, &is);
	i = -1;
	while (++i < hgt)
	{
		j = -1;
		while (++j < wgt)
			new_f[i][j] = (*fig)[is + i][js + j];
	}
	free(*fig);
	*fig = new_f;
	return (1);
}
