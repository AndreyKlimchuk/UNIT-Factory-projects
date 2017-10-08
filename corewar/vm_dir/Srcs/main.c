/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:11:29 by aklimchu          #+#    #+#             */
/*   Updated: 2017/03/31 15:03:13 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/vm.h"

void				usage(t_state *s)
{
	ft_printf("Usage:  ./corewar [flags] champion1.cor ...\n\n");
	ft_printf("Next flags are available:\n");
	ft_printf("%-25s- set the number of the next player\n", "-n [number]");
	ft_printf("%-25s", "-dump [nbr_cycles]");
	ft_printf("- after nbr_cycles dump the memmory and quit the game\n");
	ft_printf("%-25s- turn on the vizualizator\n", "-v");
	ft_printf("%-25s- hide the announcement of live function\n", "-hide");
	exit_failure(NULL, NULL, s);
}

void				clear_state(t_state *s)
{
	unsigned int	i;
	t_list			*curr;
	t_list			*temp;

	i = 0;
	if (s->players)
	{
		while (i < s->player_nums)
		{
			free(s->players[i].name);
			free(s->players[i].desc);
			free(s->players[i].init_prog_code);
			i++;
		}
		free(s->players);
	}
	curr = s->proc;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free(temp->content);
		free(temp);
	}
}

void				init_state(t_state *s)
{
	int				i;

	ft_memset(s, 0, sizeof(t_state));
	s->running = VM_TRUE;
	s->cycle_to_die = CYCLE_TO_DIE;
	i = 0;
	while (i < MEM_SIZE)
		s->color_matrix[i++].p_idx = -1;
	if (!(s->players = (t_player*)malloc(sizeof(t_player) * MAX_PLAYERS)))
		exit_failure("Bad memory allocation\n", NULL, s);
}

int					main(int argc, char **argv)
{
	t_state			s;

	init_state(&s);
	if (argc == 1)
		usage(&s);
	else
	{
		handle_args(argc, argv, &s);
		load_champs(&s);
		run(&s);
	}
	clear_state(&s);
	return (0);
}
