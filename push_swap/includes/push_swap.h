/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:50:33 by aklimchu          #+#    #+#             */
/*   Updated: 2017/01/29 19:25:40 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

typedef struct	s_flags
{
	char		debug;
	char		color;
	char		op_num;
}				t_flags;

typedef struct	s_stack
{
	t_dlist		*top;
	t_dlist		*bot;
	int			height;
}				t_stack;

typedef	struct	s_opers
{
	char		*oper;
	short		index;
	void		(*f)(t_stack*, int);
}				t_opers;

typedef struct	s_stdarr
{
	int			*arr;
	int			sz;
	int			idx[2];
}				t_stdarr;

int				prep_s(t_stack **stack);
t_opers			*arr_init(void);
int				is_sort(t_dlist *node);
int				check_flags(int ac, char **av, t_flags *fls);
void			print_stacks(t_stack *stk, short color, char *oper);
void			print_el(char *str, short color, int l_br, int fd);
void			print_op_num(int op_num, short color);
int				check_and_add(char *str, t_stack *stk);
int				get_args(int ac, char **av, t_stack *stk, int i);
void			swap(t_stack *stack, int index);
void			rotate(t_stack *stack, int index);
void			rev_rot(t_stack *stack, int index);
void			push(t_stack *stack, int index);
int				cmp(t_dlist *first, t_dlist *second);
void			selection_sort(t_stack *stk);
void			perform(void (*f)(t_stack*, int), int idx, t_stack *stk);
int				*get_sorted_arr(t_stack *stk, int idx, int size);
void			quick_sort(int n, int idx, t_stack *stk);

#endif
