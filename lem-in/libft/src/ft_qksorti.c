/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qksorti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 16:37:59 by aklimchu          #+#    #+#             */
/*   Updated: 2017/02/06 11:21:03 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap(int *arr, int idx1, int idx2)
{
	int		temp;

	if (idx1 != idx2)
	{
		temp = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = temp;
	}
}

static int	partition(int *arr, int start, int end)
{
	int		p_idx;
	int		pivot;

	p_idx = ft_rand(start, end);
	swap(arr, p_idx, end);
	p_idx = start;
	pivot = arr[end];
	while (start < end)
	{
		if (arr[start] < pivot)
			swap(arr, p_idx++, start);
		start++;
	}
	swap(arr, p_idx, end);
	return (p_idx);
}

void		ft_qksorti(int *arr, int start, int end)
{
	int		p_idx;

	if (start < end)
	{
		p_idx = partition(arr, start, end);
		ft_qksorti(arr, start, p_idx - 1);
		ft_qksorti(arr, p_idx + 1, end);
	}
}
