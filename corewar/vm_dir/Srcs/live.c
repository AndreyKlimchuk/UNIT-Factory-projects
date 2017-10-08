/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:35:10 by aklimchu          #+#    #+#             */
/*   Updated: 2017/04/02 14:06:59 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/vm.h"

int					search_player(int p_num, t_state *s)
{
	unsigned int	i;

	i = 0;
	while (i < s->player_nums - 1 && s->players[i].num != p_num)
		i++;
	if (s->players[i].num == p_num)
		return (i);
	else
		return (-1);
}

void				i_live(t_arg *args, t_process *p, t_state *s)
{
	int				p_num;
	int				idx;

	p_num = args[0].val;
	p->live_in_curr_per++;
	s->total_live_in_curr_per++;
	s->color_matrix[p->pc - s->arena].bright = LIVE_BRIHT_CYCL;
	if ((idx = search_player(p_num, s)) > -1)
	{
		s->players[idx].live_in_curr_per++;
		s->players[idx].last_live = s->total_cycles;
		if (!s->visu && !s->hide)
			ft_printf("A process shows that player %d (%s) is alive\n",
				s->players[idx].num, s->players[idx].name);
	}
}
