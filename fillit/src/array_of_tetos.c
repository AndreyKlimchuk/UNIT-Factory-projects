/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_of_tetos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:29:44 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/03 13:08:51 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tetri.h>

short		count_file(char *src)
{
	int		i;

	i = 0;
	while (src[i])
		i++;
	return ((i + 1) / 21);
}

/*
** c_c stands for continue check
*/

static int	c_c(char **fg, int i, int j, int ps)
{
	int ans;

	if (fg[i][j] == PUST)
		return (0);
	ans = 1;
	ans += (j < 3 && ps != -1) ? c_c(fg, i, j + 1, 1) : 0;
	ans += (j && ps != 1) ? c_c(fg, i, j - 1, -1) : 0;
	ans += (i < 3) ? c_c(fg, i + 1, j, 0) : 0;
	return (ans);
}

static int	check_source(char *src)
{
	int	i;
	int s_c;
	int in;

	i = -1;
	s_c = 0;
	in = 0;
	while (src[++i])
	{
		if (!((i + 1) % 21))
		{
			if (src[i] != '\n' || s_c != 4)
				error("error", 1, 1);
			s_c = 0;
			in++;
			i++;
		}
		if (!((i + 1 - in) % 5) && src[i] != '\n')
			error("error", 1, 1);
		if (((i + 1 - in) % 5) && src[i] != '.' && src[i] != '#')
			error("error", 1, 1);
		if (src[i] == '#' && ++s_c > 4)
			error("error", 1, 1);
	}
	return ((((i + 1) % 21) || s_c != 4) ? (int)error("error", 1, 1) : 1);
}

static int	check_figure(char **fig)
{
	int i;
	int j;

	i = -1;
	while (++(i) < 4)
	{
		j = -1;
		while (++(j) < 4)
			if (fig[i][j] != PUST)
				break ;
		if (fig[i][j] != PUST)
			break ;
	}
	return ((c_c(fig, i, j, 0) < 4) ? (int)error("error", 1, 1) : 1);
}

t_etos		*make_array(char *src)
{
	char	**one_fig;
	t_etos	*figures;
	int		i;

	if (!check_source(src))
		error("error", 1, 1);
	if (!(figures = (t_etos *)malloc(sizeof(t_etos) * (count_file(src) + 1))))
		error("No memory!", 2, 2);
	i = 0;
	while (*src)
	{
		if (i > 26)
			error("error", 1, 1);
		if (!(one_fig = one_figure(src, i)) || !(check_figure(one_fig)))
			return (0);
		src += (*(src + 20) == '\n') ? 21 : 20;
		fill_fig(get_height(&one_fig), get_width(&one_fig), i, &(figures[i]));
		if (!(smaller(&one_fig, figures[i].height, figures[i].width)))
			return (0);
		figures[i].shift = get_shift(one_fig, figures[i].width);
		figures[i].figure = one_fig;
		i++;
	}
	figures[i].figure = 0;
	return (figures);
}
