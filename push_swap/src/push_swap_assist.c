/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_assist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:43:30 by aklimchu          #+#    #+#             */
/*   Updated: 2017/01/30 16:48:25 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*get_sorted_arr(t_stack *stk, int idx, int size)
{
	int		*arr;
	t_dlist	*curr_node;
	int		i;

	i = 0;
	curr_node = stk[idx].top;
	arr = (int*)malloc(sizeof(int) * size);
	while (i < size && curr_node)
	{
		arr[i++] = *((int*)curr_node->content);
		curr_node = curr_node->prev;
	}
	ft_qksorti(arr, 0, size - 1);
	return (arr);
}
