/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:50:50 by aklimchu          #+#    #+#             */
/*   Updated: 2017/01/30 12:25:55 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				prep_f(t_flags **fls)
{
	if (!(*fls = malloc(sizeof(t_flags))))
		return (0);
	(*fls)->debug = 0;
	(*fls)->color = 0;
	(*fls)->op_num = 0;
	return (1);
}

int				read_and_exec(t_stack *stk, t_flags *fls)
{
	t_opers		*arr;
	char		*str;
	int			op_num;
	int			i;

	arr = arr_init();
	if (fls->debug)
		print_stacks(stk, fls->color, "Init A and B:");
	op_num = 0;
	while (get_next_line(0, &str))
	{
		i = 0;
		while (!ft_strequ(arr[i].oper, str) && arr[i].f)
			i++;
		free(str);
		if (!(arr[i].f))
			return (0);
		arr[i].f(stk, arr[i].index);
		if (fls->debug)
			print_stacks(stk, fls->color, arr[i].oper);
		op_num++;
	}
	if (fls->op_num)
		print_op_num(op_num, fls->color);
	return ((is_sort(stk[0].bot) && !(stk[1].bot)) ? 1 : -1);
}

int				main(int argc, char **argv)
{
	int			i;
	int			ret;
	t_stack		*stk;
	t_flags		*fls;

	if (!prep_s(&stk) || !prep_f(&fls))
	{
		write(2, "Allocation failed\n", 19);
		return (0);
	}
	i = check_flags(argc, argv, fls);
	if (i == argc)
		return (0);
	if (!i || !get_args(argc, argv, stk, i) || !(ret = read_and_exec(stk, fls)))
		print_el("Error", fls->color * 1, 1, 2);
	else if (ret == -1)
		print_el("KO", fls->color * 1, 1, 1);
	else if (ret == 1)
		print_el("OK", fls->color * 2, 1, 1);
	free(fls);
	ft_dlstdel(&stk[0].bot, &ft_lstdelcont);
	ft_dlstdel(&stk[1].bot, &ft_lstdelcont);
	free(stk);
	return (0);
}
