/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:08:14 by aklimchu          #+#    #+#             */
/*   Updated: 2017/03/31 14:37:07 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/vm.h"

static void					update_process(t_process *p, t_state *s)
{
	if (p->wait_cycles > 1)
		p->wait_cycles--;
	else if (p->wait_cycles == 1)
	{
		p->wait_cycles--;
		exec_instr(p, s);
	}
	else if (*(p->pc) >= 1 && *(p->pc) <= 16)
	{
		p->curr_opcode = *(p->pc);
		p->wait_cycles = g_op_tab[p->curr_opcode - 1].cycles - 1;
		if (p->wait_cycles == 0)
			exec_instr(p, s);
	}
	else
		p->pc = move_to(1, p->pc, s->arena);
}

static void					update_proc_states(t_state *s)
{
	t_list					*curr_p;

	curr_p = s->proc;
	while (curr_p != NULL)
	{
		if (s->curr_period_cycles == s->cycle_to_die &&
			!(PROC(curr_p)->live_in_curr_per))
		{
			curr_p = kill_process(&curr_p, &(s->proc));
			s->process_nums--;
			if (!s->process_nums)
				s->running = VM_FALSE;
		}
		else
		{
			update_process(PROC(curr_p), s);
			curr_p = curr_p->next;
		}
	}
}

static void					reset_counters(t_state *s)
{
	t_list					*cursor;
	unsigned int			i;

	i = 0;
	while (i < s->player_nums)
		s->players[i++].live_in_curr_per = 0;
	cursor = s->proc;
	while (cursor)
	{
		PROC(cursor)->live_in_curr_per = 0;
		cursor = cursor->next;
	}
	s->curr_period_cycles = 0;
	s->total_live_in_curr_per = 0;
}

static void					start_new_period(t_state *s)
{
	if (s->total_live_in_curr_per >= NBR_LIVE)
		decrease_cycle_to_die(s);
	s->checks_num++;
	if (s->checks_num == MAX_CHECKS)
	{
		if (!(s->ctd_decreased))
			decrease_cycle_to_die(s);
		s->checks_num = 0;
		s->ctd_decreased = VM_FALSE;
	}
	reset_counters(s);
}

void						run(t_state *s)
{
	int						ch;

	ch = 32;
	if (s->visu)
		init_visualizer(s);
	while (s->running)
	{
		if (s->visu)
		{
			update_visualizer(s, ch);
			ch = getch();
		}
		if (s->dump && s->total_cycles == s->cycle_limit)
			dump(s);
		s->total_cycles++;
		s->curr_period_cycles++;
		update_proc_states(s);
		if (s->curr_period_cycles == s->cycle_to_die)
			start_new_period(s);
	}
	if (s->visu)
		end_visu(s, 0);
	announce_winner(s);
}
