/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:56:46 by aklimchu          #+#    #+#             */
/*   Updated: 2017/03/22 17:56:48 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/vm.h"

void	i_zjmp(t_arg *args, t_process *p, t_state *s)
{
	int bytes;

	if (p->carry == TRUE)
	{
		bytes = args[0].val % IDX_MOD;
		p->pc = move_to(bytes, p->pc, s->arena);
		p->skip_bytes = FALSE;
	}
}
