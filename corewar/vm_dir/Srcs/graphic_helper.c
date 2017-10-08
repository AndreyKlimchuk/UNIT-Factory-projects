/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 14:43:05 by aklimchu          #+#    #+#             */
/*   Updated: 2017/03/31 14:58:40 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/vm.h"

static void	print_players(t_state *s, int *i, int tab)
{
	while (*i < s->player_nums)
	{
		mvprintw(12 + *i * 4, tab, "Player %-10i       :",
			(s->players)[*i].num);
		attron(COLOR_PAIR(*i + 1));
		mvprintw(12 + *i * 4, tab + 26, "%.25s", s->players[*i].name);
		attroff(COLOR_PAIR(*i + 1));
		mvprintw(13 + *i * 4, tab, "Last live               : %-9zu ",
			(s->players)[*i].last_live);
		mvprintw(14 + *i * 4, tab, "Lives in current period : %-9zu",
			(s->players)[*i].live_in_curr_per);
		++*i;
	}
}

void		draw_sidebar(t_state *s)
{
	int		i;
	int		tab;

	i = 0;
	tab = 203;
	attron(A_BOLD);
	mvprintw(3, tab + 17, "%s", "** RUNNING **", A_BOLD);
	mvprintw(6, tab, "%s%-8d", "Cycle       : ", s->total_cycles);
	mvprintw(8, tab, "%s%-8d", "Processes   : ", s->process_nums);
	print_players(s, &i, tab);
	mvprintw(14 + i * 4, tab, "%s%-8d", "CYCLE_TO_DYE : ", s->cycle_to_die);
	mvprintw(14 + i * 4 + 2, tab, "%s%-8d", "CYCLE_DELTA  : ", CYCLE_DELTA);
	mvprintw(14 + i * 4 + 4, tab, "%s%-8d", "NBR_LIVE     : ",
		s->total_live_in_curr_per);
	mvprintw(14 + i * 4 + 6, tab, "%s%-8d", "MAX_CHEKS    : ", MAX_CHECKS);
	mvprintw(14 + i * 4 + 8, tab, "%s%-8d", "CURR_CHEKS   : ", s->checks_num);
	mvprintw(14 + i * 4 + 10, tab, "%s%-8d", "SPEED        : ",
		8 - s->delay / 10000);
	attroff(A_BOLD);
	refresh();
}

static int	define_attr(t_state *s, int i)
{
	int		pair_code;

	pair_code = s->color_matrix[i].p_idx + 1;
	if (s->color_matrix[i].bright > 0)
	{
		attron(A_BOLD);
		s->color_matrix[i].bright--;
	}
	else if (s->color_matrix[i].bright < 0)
	{
		pair_code += 4;
		attron(A_BOLD);
		s->color_matrix[i].bright++;
	}
	attron(COLOR_PAIR(pair_code));
	return (pair_code);
}

static void	place_pcs(t_state *s)
{
	t_list	*cursor;
	int		pos;
	int		row;
	int		col;

	cursor = s->proc;
	while (cursor)
	{
		pos = (int)(PROC(cursor)->pc - s->arena);
		if (s->color_matrix[pos].bright < 0)
			attron(COLOR_PAIR(s->color_matrix[pos].p_idx + 5) | A_BOLD);
		else
			attron(COLOR_PAIR(s->color_matrix[pos].p_idx + 9));
		row = pos / 64 + 2;
		col = pos % 64;
		mvprintw(row, col * 3 + 5, "%02x", s->arena[pos]);
		if (s->color_matrix[pos].bright < 0)
			attroff(COLOR_PAIR(s->color_matrix[pos].p_idx + 5) | A_BOLD);
		else
			attroff(COLOR_PAIR(s->color_matrix[pos].p_idx + 9));
		cursor = cursor->next;
	}
}

void		draw_arena(t_state *s)
{
	int		i;
	int		row;
	int		reset_pair_code;

	row = -1;
	i = -1;
	while (++i < MEM_SIZE)
	{
		if (!(i % 64))
			row++;
		reset_pair_code = define_attr(s, i);
		mvprintw(row + 2, (i % 64) * 3 + 5, "%02x", s->arena[i]);
		attroff(COLOR_PAIR(reset_pair_code) | A_BOLD);
		mvprintw(row + 2, (i % 64) * 3 + 7, " ");
	}
	place_pcs(s);
}
