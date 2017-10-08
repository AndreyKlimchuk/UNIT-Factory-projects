/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 14:09:39 by aklimchu          #+#    #+#             */
/*   Updated: 2017/03/31 14:24:05 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/vm.h"

static void	dump_memory(unsigned char *memory)
{
	int		i;
	int		printed;

	printed = 0;
	while (printed < MEM_SIZE)
	{
		i = -1;
		while (++i < 32 && printed + i < MEM_SIZE)
		{
			ft_printf("%2.2x ", *memory);
			memory++;
		}
		ft_printf("\n");
		printed += i;
	}
}

void		dump(t_state *s)
{
	if (s->visu)
		end_visu(s, 1);
	dump_memory(s->arena);
	clear_state(s);
	exit(EXIT_SUCCESS);
}
