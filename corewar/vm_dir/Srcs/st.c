/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:20:04 by aklimchu          #+#    #+#             */
/*   Updated: 2017/03/31 15:03:49 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/vm.h"

void				i_st(t_arg *args, t_process *p, t_state *s)
{
	int				val;
	int				address;
	unsigned char	*pos;
	int				i;

	val = get_arg_val(args[0], p, s->arena, 4);
	if (args[1].type == T_IND)
	{
		address = args[1].val % IDX_MOD;
		pos = move_to(address, p->pc, s->arena);
		write_mem(val, pos, s->arena);
		address = (int)(pos - s->arena);
		i = -1;
		while (++i < 4)
		{
			s->color_matrix[address % MEM_SIZE].p_idx =
					(char)search_player(p->player_num, s);
			s->color_matrix[address % MEM_SIZE].bright = BRIHT_CYCL;
			address++;
		}
	}
	else if (args[1].type == T_REG)
		if (args[1].val >= 1 && args[1].val <= 16)
			p->regs[args[1].val - 1] = get_arg_val(args[0], p, s->arena, 4);
}
