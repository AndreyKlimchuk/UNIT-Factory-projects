/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:59:58 by aklimchu          #+#    #+#             */
/*   Updated: 2017/03/22 14:59:59 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/vm.h"

void	i_ld(t_arg *args, t_process *p, t_state *s)
{
	int	val;

	if (args[0].type == T_IND)
		args[0].val %= IDX_MOD;
	val = get_arg_val(args[0], p, s->arena, 4);
	if (args[1].val > 0 && args[1].val <= REG_NUMBER)
		p->regs[args[1].val - 1] = val;
	if (!val)
		p->carry = TRUE;
	else
		p->carry = FALSE;
}
