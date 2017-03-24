/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 11:14:30 by aklimchu          #+#    #+#             */
/*   Updated: 2017/02/19 09:49:10 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		init_state(t_state **st, char *prog_name)
{
	char	*str;

	*st = (t_state*)malloc(sizeof(t_state));
	(*st)->map = (t_map*)malloc(sizeof(t_map));
	(*st)->fig = (t_piece*)malloc(sizeof(t_piece));
	get_next_line(0, &str);
	if (ft_strstr(str, prog_name) && ft_strstr(str, "p1"))
	{
		(*st)->my_c = 'O';
		(*st)->enemy_c = 'X';
	}
	else
	{
		(*st)->my_c = 'X';
		(*st)->enemy_c = 'O';
	}
	free(str);
}

int			main(int argc, char **argv)
{
	t_state	*st;
	t_pos	*pos;
	char	*str;
	int		i;

	i = 0;
	(void)argc;
	init_state(&st, argv[0]);
	while (get_next_line(0, &str))
	{
		st->map = (!i) ? get_map(&str, st->map) : update_map(&str, st->map);
		st->fig = get_fig(&str, st->fig);
		weight_the_map(st);
		pos = choose_pos(st);
		if (pos->fig_weight != INT_MAX)
			print_pos(pos->x, pos->y);
		else
			print_pos(0, 0);
		free(pos);
		erase_fig(&(st->fig->shape));
		i++;
	}
	del_all(&st);
	return (0);
}
