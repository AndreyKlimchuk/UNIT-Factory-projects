/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 19:28:44 by aklimchu          #+#    #+#             */
/*   Updated: 2017/02/06 11:04:42 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			choose_pivot(t_stack *stk, int idx, int size)
{
	int		*arr;
	int		pivot;

	arr = get_sorted_arr(stk, idx, size);
	pivot = arr[size / 2];
	free(arr);
	return (pivot);
}

void		push_and_sort(int n, t_stack *stk)
{
	while (n--)
	{
		if (n > 0 && cmp(stk[1].top->prev, stk[1].top))
			perform(&swap, 1, stk);
		perform(&push, 0, stk);
		if (cmp(stk[0].top, stk[0].top->prev))
			perform(&swap, 0, stk);
	}
}

void		small_sort(int n, int idx, t_stack *stk)
{
	if (idx && !(idx = 0))
		push_and_sort(n, stk);
	if (n == 3)
	{
		if (cmp(stk[idx].top, stk[idx].top->prev))
			perform(&swap, idx, stk);
		if (cmp(stk[idx].top, stk[idx].top->prev->prev) ||
			cmp(stk[idx].top->prev, stk[idx].top->prev->prev))
		{
			perform(&rotate, idx, stk);
			perform(&swap, idx, stk);
			perform(&rev_rot, idx, stk);
		}
	}
	if (cmp(stk[idx].top, stk[idx].top->prev))
		perform(&swap, idx, stk);
}

int			push_next_part(int np, int piv, t_stack *stk, int idx)
{
	int		rot_num;
	int		i;

	rot_num = 0;
	i = 0;
	while (i < np)
	{
		if ((!idx && *((int*)stk[idx].top->content) < piv) ||
			(idx && *((int*)stk[idx].top->content) >= piv))
		{
			perform(&push, 1 - idx, stk);
			i++;
		}
		else
		{
			perform(&rotate, idx, stk);
			rot_num++;
		}
	}
	return (rot_num);
}

void		quick_sort(int n, int idx, t_stack *stk)
{
	int		pivot;
	int		next_part;
	int		rot_num;

	if (n > 3)
	{
		pivot = choose_pivot(stk, idx, n);
		next_part = ((idx && n % 2) ? 1 : 0) + n / 2;
		rot_num = push_next_part(next_part, pivot, stk, idx);
		if (n - next_part != stk[idx].height)
			while (rot_num--)
				perform(&rev_rot, idx, stk);
		quick_sort((idx ? next_part : n - next_part),
			(idx ? 1 - idx : idx), stk);
		quick_sort((idx ? n - next_part : next_part),
			(idx ? idx : 1 - idx), stk);
	}
	else
		small_sort(n, idx, stk);
}
