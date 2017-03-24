/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:05:57 by aklimchu          #+#    #+#             */
/*   Updated: 2017/02/12 13:30:57 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		increase_dist(t_list **sol, int i)
{
	t_list	*curr;

	curr = sol[i];
	if (curr && curr->next)
	{
		while (curr->next)
		{
			MOVE(curr)->room->dist++;
			curr = curr->next;
		}
	}
}

void		add_to_solution(t_list **sol, int i, t_room *curr_pos, int step)
{
	t_move	*new_move;

	new_move = (t_move*)malloc(sizeof(t_move));
	new_move->step_num = step;
	new_move->room = curr_pos;
	ft_lstaddback(sol + i, ft_lstpnew(new_move, sizeof(t_move)));
}

void		print_move(t_list **sol, int i, int moves)
{
	t_list	*temp;

	temp = sol[i];
	sol[i] = sol[i]->next;
	if (moves > 1)
		ft_putchar(' ');
	ft_putchar('L');
	ft_putnbr(i + 1);
	ft_putchar('-');
	ft_putstr(MOVE(temp)->room->name);
	free(temp->content);
	free(temp);
}

void		print_solution(t_list **sol, t_farm *farm)
{
	int		moves;
	int		i;
	int		curr_step;

	moves = 1;
	curr_step = 0;
	while (moves)
	{
		i = -1;
		moves = 0;
		curr_step++;
		while (++i < farm->unt_num)
		{
			if (sol[i] && MOVE(sol[i])->step_num == curr_step)
			{
				moves++;
				print_move(sol, i, moves);
			}
		}
		if (moves)
			write(1, "\n", 1);
	}
}

void		sort(t_list **sol, int n)
{
	int		i;
	int		hole;
	t_list	*temp;

	i = 1;
	while (i < n)
	{
		temp = sol[i];
		hole = i;
		while (hole > 0 && MOVE(sol[hole - 1])->step_num >
		MOVE(temp)->step_num)
		{
			sol[hole] = sol[hole - 1];
			hole--;
		}
		sol[hole] = temp;
		i++;
	}
}
