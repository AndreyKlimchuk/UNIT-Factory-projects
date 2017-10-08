/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:47:46 by aklimchu          #+#    #+#             */
/*   Updated: 2017/03/31 15:04:18 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/vm.h"

void				i_sti(t_arg *args, t_process *p, t_state *s)
{
	int				val;
	int				address;
	unsigned char	*pos;
	int				i;

	val = get_arg_val(args[0], p, s->arena, 4);
	address = (get_arg_val(args[1], p, s->arena, 4) +
			get_arg_val(args[2], p, s->arena, 4)) % IDX_MOD;
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
