/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:25:02 by aklimchu          #+#    #+#             */
/*   Updated: 2017/01/27 19:15:27 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				prep_s(t_stack **stack)
{
	if (!(*stack = (t_stack*)malloc(sizeof(t_stack) * 2)))
		return (0);
	(*stack)[0].top = NULL;
	(*stack)[0].bot = NULL;
	(*stack)[0].height = 0;
	(*stack)[1].top = NULL;
	(*stack)[1].bot = NULL;
	(*stack)[1].height = 0;
	return (1);
}

t_opers			*arr_init(void)
{
	static t_opers	arr[] = {{"sa", 0, &swap}, {"sb", 1, &swap},
	{"ss", 2, &swap}, {"pa", 0, &push}, {"pb", 1, &push},
	{"ra", 0, &rotate}, {"rb", 1, &rotate}, {"rr", 2, &rotate},
	{"rra", 0, &rev_rot}, {"rrb", 1, &rev_rot},
	{"rrr", 2, &rev_rot}, {"\0", 0, NULL}};

	return (arr);
}

int				check_and_add(char *str, t_stack *stk)
{
	int			i;
	long long	num;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] && i < 12)
		if (!(ft_isdigit(str[i++])))
			return (0);
	if (str[i] || ((str[0] == '-' || str[0] == '+') && i == 1))
		return (0);
	num = ft_atoll(str);
	if (num > INT_MAX || num < INT_MIN ||
		ft_dlstsrch(stk[0].bot, (void*)&num, sizeof(int)))
		return (0);
	ft_dlstadd(&(stk[0].bot), ft_dlstnew((void*)&num, sizeof(int)));
	stk[0].height++;
	if (!stk[0].top)
		stk[0].top = stk[0].bot;
	return (1);
}

int				get_args(int ac, char **av, t_stack *stk, int i)
{
	while (i < ac)
		if (!(check_and_add(av[i++], stk)))
			return (0);
	return (1);
}

int				cmp(t_dlist *first, t_dlist *second)
{
	return (*((int*)first->content) > *((int*)second->content));
}
