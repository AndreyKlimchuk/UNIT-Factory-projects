/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 10:47:24 by aklimchu          #+#    #+#             */
/*   Updated: 2017/02/12 12:46:55 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list		*compare_pos(t_list *best_pos, t_list *alt_pos, int curr_step)
{
	int		best_weight;
	int		alt_weight;
	int		diff;

	diff = ROOM(best_pos)->step - curr_step;
	best_weight = ROOM(best_pos)->dist + ((diff > 0) ? diff : 0);
	diff = ROOM(alt_pos)->step - curr_step;
	alt_weight = ROOM(alt_pos)->dist + ((diff > 0) ? diff : 0);
	if (alt_weight != best_weight)
	{
		if (alt_weight < best_weight)
			return (alt_pos);
	}
	else
	{
		if (ROOM(alt_pos)->link_num < ROOM(best_pos)->link_num)
			return (alt_pos);
	}
	return (best_pos);
}

t_room		*choose_pos(t_room *curr_pos)
{
	t_list	*best_pos;
	t_list	*link;
	int		curr_step;

	best_pos = NULL;
	link = curr_pos->links;
	curr_step = curr_pos->step;
	while (link)
	{
		if (!best_pos)
			best_pos = link;
		else
			best_pos = compare_pos(best_pos, link, curr_step);
		link = link->next;
	}
	return (ROOM(best_pos));
}

void		pave_way(t_list **sol, int i, t_farm *farm)
{
	t_room	*curr_pos;
	t_room	*next_pos;
	int		turn;

	turn = 0;
	curr_pos = ROOM(farm->start);
	while (curr_pos != ROOM(farm->end))
	{
		next_pos = choose_pos(curr_pos);
		while (turn < next_pos->step && next_pos != ROOM(farm->end))
		{
			increase_dist(sol, i);
			turn++;
		}
		turn++;
		curr_pos = next_pos;
		if (curr_pos != ROOM(farm->end))
			curr_pos->step = turn;
		add_to_solution(sol, i, curr_pos, turn);
	}
}

void		determine_dist(t_list *curr)
{
	t_list	*queue;
	t_list	*link;

	queue = NULL;
	ROOM(curr)->dist = 0;
	ft_lstaddback(&queue, ft_lstpnew(curr->content, sizeof(t_room)));
	while (queue)
	{
		curr = queue;
		queue = queue->next;
		link = ROOM(curr)->links;
		while (link)
		{
			if (ROOM(link)->dist == -1)
			{
				ROOM(link)->dist = ROOM(curr)->dist + 1;
				ft_lstaddback(&queue,
						ft_lstpnew(link->content, sizeof(t_room)));
			}
			link = link->next;
		}
		free(curr);
	}
}

char		solve(t_farm *farm)
{
	t_list	**solution;
	int		i;

	determine_dist(farm->end);
	if (ROOM(farm->start)->dist == -1)
		return (0);
	ROOM(farm->start)->dist = INT_MAX;
	i = -1;
	solution = (t_list**)malloc(sizeof(t_list*) * farm->unt_num + 1);
	while (++i <= farm->unt_num)
		solution[i] = NULL;
	i = 0;
	while (i < farm->unt_num)
		pave_way(solution, i++, farm);
	sort(solution, farm->unt_num);
	ft_putstr(farm->map_desc);
	write(1, "\n", 1);
	print_solution(solution, farm);
	free(solution);
	return (1);
}
