/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debbuger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:17:15 by aklimchu          #+#    #+#             */
/*   Updated: 2017/01/27 12:21:58 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_flags(int ac, char **av, t_flags *fls)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac && av[i][0] == '-' && !ft_isdigit(av[i][1]))
	{
		if (!av[i][1])
			return (0);
		j = 0;
		while (av[i][++j])
		{
			if (av[i][j] == 'c')
				fls->color = 1;
			else if (av[i][j] == 'v')
				fls->debug = 1;
			else if (av[i][j] == 'n')
				fls->op_num = 1;
			else
				return (0);
		}
		i++;
	}
	return (i);
}

void		print_op_num(int op_num, short color)
{
	char	*str;

	str = ft_itoa(op_num);
	print_el("Number of executed operations: ", color * 5, 0, 1);
	print_el(str, color * 5, 1, 1);
	free(str);
}

static char	*get_el(int row, int col, t_dlist *node)
{
	char	*str;
	int		diff;

	if (row == 2)
		str = ft_strdup("_");
	else if (row == 1 && col == 0)
		str = ft_strdup("A");
	else if (row == 1 && col == 1)
		str = ft_strdup("B");
	else if (node)
		str = ft_itoa(*((int*)node->content));
	else
		str = ft_strdup(" ");
	diff = 12 - ft_strlen(str);
	while (diff--)
		write(1, " ", 1);
	return (str);
}

void		print_el(char *str, short color, int l_br, int fd)
{
	if (color == 1)
		write(1, RED, 5);
	else if (color == 2)
		write(1, GREEN, 5);
	else if (color == 3)
		write(1, YELLOW, 5);
	else if (color == 4)
		write(1, BLUE, 5);
	else if (color == 5)
		write(1, MAGENTA, 5);
	else if (color == 6)
		write(1, CYAN, 5);
	ft_putstr_fd(str, fd);
	if (color)
		write(1, RESET, 4);
	while (l_br--)
		write(1, "\n", 1);
}

void		print_stacks(t_stack *stk, short color, char *oper)
{
	int		row;
	int		col;
	int		i;
	char	*str;
	t_dlist	*temp;

	print_el(oper, color * 6, 2, 1);
	row = ((stk[0].height > stk[1].height) ? stk[0].height : stk[1].height) + 3;
	while (--row)
	{
		col = -1;
		while (++col < 2)
		{
			i = 0;
			temp = stk[col].bot;
			while (++i < (row - 2) && temp)
				temp = temp->next;
			str = get_el(row, col, temp);
			print_el(str, color * (col + 3), (col) ? 1 : 0, 1);
			free(str);
		}
	}
	write(1, "\n", 1);
}
