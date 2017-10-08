/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 09:55:36 by aklimchu          #+#    #+#             */
/*   Updated: 2017/03/31 14:37:41 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/vm.h"

void	init_color_pairs(void)
{
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_RED);
	init_pair(6, COLOR_WHITE, COLOR_GREEN);
	init_pair(7, COLOR_WHITE, COLOR_YELLOW);
	init_pair(8, COLOR_WHITE, COLOR_BLUE);
	init_pair(9, COLOR_BLACK, COLOR_RED);
	init_pair(10, COLOR_BLACK, COLOR_GREEN);
	init_pair(11, COLOR_BLACK, COLOR_YELLOW);
	init_pair(12, COLOR_BLACK, COLOR_BLUE);
	init_pair(13, COLOR_BLACK, COLOR_WHITE);
	init_pair(14, COLOR_WHITE, COLOR_WHITE);
}

void	init_visualizer(t_state *s)
{
	s->delay = 20000;
	initscr();
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);
	keypad(stdscr, TRUE);
	start_color();
	init_color_pairs();
}
