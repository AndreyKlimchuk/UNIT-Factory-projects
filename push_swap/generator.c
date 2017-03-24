/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:33:01 by aklimchu          #+#    #+#             */
/*   Updated: 2017/01/26 19:31:28 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_repetition(int *arr, int bound, int num)
{
	int	i;

	i = -1;
	while (++i <= bound)
		if (arr[i] == num)
			return (0);
	return (1);
}

void	form_sequence(int qtt, int min, int max)
{
	int	rand_num;
	int	curr_idx;
	int	*arr;

	curr_idx = -1;
	arr = (int*)malloc(sizeof(int) * qtt);
	while (curr_idx < qtt - 1)
	{
		rand_num = ft_randi(min, max);
		if (check_repetition(arr, curr_idx, rand_num))
			arr[++curr_idx] = rand_num;
	}
	while (curr_idx >= 0)
	{
		ft_putnbr(arr[curr_idx]);
		if (curr_idx > 0)
			write(1, " ", 1);
		curr_idx--;
	}
	free(arr);
}

int		main(int argc, char **argv)
{
	int	quantity;
	int	min;
	int	max;

	if (argc == 4)
	{
		quantity = ft_atoi(argv[1]);
		min = ft_atoi(argv[2]);
		max = ft_atoi(argv[3]);
		if (quantity <= 0 || min < 0 || min >= max ||
			(max - min + 1) < quantity)
			write(2, "Wrong arguments\n", 16);
		else
			form_sequence(quantity, min, max);
	}
	else
		write(2, "Wrong number of arguments\n", 26);
	return (0);
}
