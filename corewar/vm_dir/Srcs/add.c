/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:40:29 by aklimchu          #+#    #+#             */
/*   Updated: 2017/03/22 16:40:30 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/vm.h"

void	i_add(t_arg *args, t_process *p, t_state *s)
{
	int	sum;

	sum = get_arg_val(args[0], p, s->arena, 4) +
			get_arg_val(args[1], p, s->arena, 4);
	if (args[2].val > 0 && args[2].val <= REG_NUMBER)
		p->regs[args[2].val - 1] = sum;
	if (!sum)
		p->carry = TRUE;
	else
		p->carry = FALSE;
}
