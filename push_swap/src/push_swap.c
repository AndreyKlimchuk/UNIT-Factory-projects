/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:32:28 by aklimchu          #+#    #+#             */
/*   Updated: 2017/01/30 16:45:41 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		perform(void (*f)(t_stack*, int), int idx, t_stack *stk)
{
	int		i;
	t_opers	*arr;

	i = 0;
	arr = arr_init();
	while ((f != arr[i].f || idx != arr[i].index) && arr[i].f)
		i++;
	f(stk, idx);
	ft_putendl(arr[i].oper);
}

void		sort_small(t_stack *stk)
{
	while (!is_sort(stk[0].bot) || !is_sort(stk[1].bot))
	{
		if (!is_sort(stk[1].bot) && cmp(stk[0].top, stk[0].top->prev) &&
			cmp(stk[1].top, stk[1].top->prev))
			perform(&swap, 2, stk);
		else if (cmp(stk[0].top, stk[0].top->prev))
			perform(&swap, 0, stk);
		else if (!is_sort(stk[1].bot) &&
			cmp(stk[1].top, stk[1].top->prev))
			perform(&swap, 1, stk);
		else if (!is_sort(stk[0].bot) && !is_sort(stk[1].bot))
			perform(&rev_rot, 2, stk);
		else if (!is_sort(stk[0].bot))
			perform(&rev_rot, 0, stk);
		else if (!is_sort(stk[1].bot))
			perform(&rev_rot, 1, stk);
	}
}

void		merge_stacks(t_stack *stk)
{
	int		min;

	min = *((int*)stk[0].top->content);
	while (!is_sort(stk[0].bot) || stk[1].bot)
	{
		if (stk[1].bot && (cmp(stk[0].top, stk[1].top) ||
		(cmp(stk[1].top, stk[0].bot) &&
		*((int*)stk[0].top->content) == min)))
		{
			perform(&push, 0, stk);
			if (*((int*)stk[0].top->content) < min)
				min = *((int*)stk[0].top->content);
		}
		else
			perform(&rotate, 0, stk);
	}
}

void		start_sort(t_stack *stk)
{
	int		i;

	if (stk[0].height < 4)
		sort_small(stk);
	else if (stk[0].height > 3 && stk[0].height < 7)
	{
		i = stk[0].height / 2;
		while (i--)
			perform(&push, 1, stk);
		sort_small(stk);
		merge_stacks(stk);
	}
	else if (stk[0].height > 6)
		quick_sort(stk[0].height, 0, stk);
}

int			main(int argc, char **argv)
{
	t_stack	*stk;

	if (!prep_s(&stk))
	{
		write(2, "Allocation failed\n", 19);
		return (0);
	}
	if (argc == 1)
		return (0);
	if (!get_args(argc, argv, stk, 1))
		write(2, "Error\n", 6);
	else if (is_sort(stk[0].bot))
		return (0);
	else
		start_sort(stk);
	ft_dlstdel(&stk[0].bot, &ft_lstdelcont);
	ft_dlstdel(&stk[1].bot, &ft_lstdelcont);
	free(stk);
	return (0);
}
