/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 14:41:54 by aklimchu          #+#    #+#             */
/*   Updated: 2017/03/31 14:39:52 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/vm.h"

void		draw_borders(void)
{
	attron(COLOR_PAIR(14));
	mvhline(1, 3, '*', 194);
	mvhline(66, 3, '*', 194);
	mvvline(1, 3, '*', 66);
	mvvline(1, 197, '*', 66);
	mvhline(1, 200, '*', 55);
	mvhline(66, 200, '*', 55);
	mvvline(1, 200, '*', 66);
	mvvline(1, 255, '*', 66);
	attroff(COLOR_PAIR(14));
}

void		handle_arrows(t_state *s, int ch)
{
	if (ch == KEY_RIGHT && s->delay)
		s->delay -= 10000;
	else if (ch == KEY_LEFT && s->delay < 70000)
		s->delay += 10000;
	attron(A_BOLD);
	mvprintw(14 + s->player_nums * 4 + 10, 203, "%s%-8d", "SPEED        : ",
		8 - s->delay / 10000);
	attroff(A_BOLD);
	refresh();
}

void		handle_escape(t_state *s)
{
	endwin();
	exit_failure(NULL, NULL, s);
}

void		end_visu(t_state *s, char dump)
{
	attron(A_BOLD);
	if (dump)
		mvprintw(27 + s->player_nums * 4, 203, "Dump!");
	announce_winner(s);
	mvprintw(29 + s->player_nums * 4, 203, "Press escape to quite.");
	attroff(A_BOLD);
	refresh();
	while (getch() != 27)
		;
	handle_escape(s);
}

void		update_visualizer(t_state *s, int ch)
{
	draw_borders();
	draw_sidebar(s);
	draw_arena(s);
	refresh();
	if (ch == 27)
		handle_escape(s);
	if (ch == KEY_RIGHT || ch == KEY_LEFT)
		handle_arrows(s, ch);
	if (ch == 32)
	{
		attron(A_BOLD);
		mvprintw(3, 220, "%s", "** PAUSED ** ", A_BOLD);
		attroff(A_BOLD);
		while ((ch = getch()) != 32)
		{
			if (ch == 27)
				handle_escape(s);
			if (ch == KEY_RIGHT || ch == KEY_LEFT)
				handle_arrows(s, ch);
		}
	}
	usleep(s->delay);
}
