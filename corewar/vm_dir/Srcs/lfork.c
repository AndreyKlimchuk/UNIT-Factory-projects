/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:16:36 by aklimchu          #+#    #+#             */
/*   Updated: 2017/03/22 18:16:38 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/vm.h"

void				i_lfork(t_arg *args, t_process *p, t_state *s)
{
	t_list			*new_p;
	int				bytes;

	new_p = ft_lstnew(p, sizeof(t_process));
	bytes = args[0].val;
	PROC(new_p)->pc = move_to(bytes, p->pc, s->arena);
	s->process_nums++;
	ft_lstadd(&(s->proc), new_p);
}
