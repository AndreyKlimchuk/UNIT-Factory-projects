/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_assist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 10:28:28 by aklimchu          #+#    #+#             */
/*   Updated: 2017/03/31 14:23:08 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/vm.h"

void				decrease_cycle_to_die(t_state *s)
{
	if (s->cycle_to_die < CYCLE_DELTA)
	{
		s->running = VM_FALSE;
		s->cycle_to_die = 0;
		update_visualizer(s, 0);
	}
	s->cycle_to_die -= CYCLE_DELTA;
	s->ctd_decreased = VM_TRUE;
}

void				exec_instr(t_process *p, t_state *s)
{
	unsigned char	bytes_num;

	bytes_num = 0;
	p->skip_bytes = VM_TRUE;
	if (p->curr_opcode == *(p->pc))
		bytes_num = eval_instruction(s, p);
	p->curr_opcode = 0;
	if (p->skip_bytes)
		p->pc = move_to(bytes_num + 1, p->pc, s->arena);
}

t_list				*kill_process(t_list **to_del, t_list **head)
{
	t_list			*curr;
	t_list			*next;

	next = (*to_del)->next;
	if (*head == *to_del)
		*head = next;
	else
	{
		curr = *head;
		while (curr->next != *to_del)
			curr = curr->next;
		curr->next = next;
	}
	free((*to_del)->content);
	free(*to_del);
	return (next);
}

void				announce_winner(t_state *s)
{
	unsigned int	i;
	unsigned int	w_idx;

	i = 0;
	w_idx = 0;
	while (i < s->player_nums)
	{
		if (s->players[i].last_live > s->players[w_idx].last_live)
			w_idx = i;
		i++;
	}
	if (s->visu)
	{
		attron(COLOR_PAIR(w_idx + 1));
		mvprintw(28 + s->player_nums * 4, 203, "Player %d (%s) won",
			s->players[w_idx].num, s->players[w_idx].name);
		attroff(COLOR_PAIR(w_idx + 1));
	}
	else
		ft_printf("Player %d (%s) won\n", s->players[w_idx].num,
			s->players[w_idx].name);
}
