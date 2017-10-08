/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champions_loader.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:37:58 by aklimchu          #+#    #+#             */
/*   Updated: 2017/03/31 14:21:04 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/vm.h"

void				write_champ(t_state *s, unsigned int curr_p)
{
	int				offset;
	int				i;

	offset = curr_p * (MEM_SIZE / s->player_nums);
	ft_memcpy(s->arena + offset, s->players[curr_p].init_prog_code,
		s->players[curr_p].init_prog_size);
	i = 0;
	while (i < s->players[curr_p].init_prog_size)
		s->color_matrix[offset + i++].p_idx = (char)curr_p;
}

void				insert_proc(t_list *new_p, t_state *s)
{
	t_list			*curr;
	t_list			*prev;

	prev = NULL;
	curr = s->proc;
	while (curr && PROC(curr)->player_num > PROC(new_p)->player_num)
	{
		prev = curr;
		curr = curr->next;
	}
	if (prev)
		prev->next = new_p;
	else
		s->proc = new_p;
	new_p->next = curr;
}

void				create_proc(t_state *s, unsigned int curr_p)
{
	t_process		*proc;
	t_list			*new_p;

	proc = (t_process*)malloc(sizeof(t_process));
	ft_memset((void*)proc, 0, sizeof(t_process));
	proc->player_num = s->players[curr_p].num;
	proc->regs[0] = s->players[curr_p].num;
	proc->pc = s->arena + (curr_p * (MEM_SIZE / s->player_nums));
	proc->skip_bytes = VM_TRUE;
	new_p = ft_lstpnew((void*)proc, sizeof(t_process));
	insert_proc(new_p, s);
	s->process_nums++;
}

void				load_champs(t_state *s)
{
	unsigned int	curr_p;

	curr_p = 0;
	while (curr_p < s->player_nums)
	{
		write_champ(s, curr_p);
		create_proc(s, curr_p);
		curr_p++;
	}
}
