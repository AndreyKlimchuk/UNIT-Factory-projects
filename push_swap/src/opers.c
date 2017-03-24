/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:05:54 by aklimchu          #+#    #+#             */
/*   Updated: 2017/01/27 19:11:53 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap(t_stack *stack, int index)
{
	t_dlist	*curr;
	t_dlist	*prev;

	if (index == 2)
	{
		swap(stack, 0);
		swap(stack, 1);
	}
	else
	{
		curr = stack[index].top;
		if (curr && curr->prev)
		{
			prev = curr->prev;
			if (prev->prev)
				prev->prev->next = curr;
			else
				stack[index].bot = curr;
			curr->prev = prev->prev;
			curr->next = prev;
			prev->prev = curr;
			prev->next = NULL;
			stack[index].top = prev;
		}
	}
}

void		rotate(t_stack *stack, int index)
{
	t_dlist	*node;

	if (index == 2)
	{
		rotate(stack, 0);
		rotate(stack, 1);
	}
	else
	{
		node = stack[index].top;
		if (node && node->prev)
		{
			stack[index].top = stack[index].top->prev;
			stack[index].top->next = NULL;
			node->next = stack[index].bot;
			node->prev = NULL;
			stack[index].bot->prev = node;
			stack[index].bot = node;
		}
	}
}

void		rev_rot(t_stack *stack, int index)
{
	t_dlist	*node;

	if (index == 2)
	{
		rev_rot(stack, 0);
		rev_rot(stack, 1);
	}
	else
	{
		node = stack[index].bot;
		if (node && node->next)
		{
			stack[index].bot = stack[index].bot->next;
			stack[index].bot->prev = NULL;
			node->prev = stack[index].top;
			node->next = NULL;
			stack[index].top->next = node;
			stack[index].top = node;
		}
	}
}

void		push(t_stack *stack, int index)
{
	t_dlist	*node;
	t_dlist	*top;

	node = stack[1 - index].top;
	top = stack[index].top;
	if (node)
	{
		stack[1 - index].top = stack[1 - index].top->prev;
		if (!stack[1 - index].top)
			stack[1 - index].bot = NULL;
		else
			stack[1 - index].top->next = NULL;
		node->prev = top;
		if (top)
			top->next = node;
		else
			stack[index].bot = node;
		stack[index].top = node;
		stack[index].height++;
		stack[1 - index].height--;
	}
}

int			is_sort(t_dlist *node)
{
	if (node)
	{
		while (node->next)
		{
			if (!cmp(node, node->next))
				return (0);
			node = node->next;
		}
	}
	return (1);
}
