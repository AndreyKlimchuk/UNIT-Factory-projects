/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:09:07 by aklimchu          #+#    #+#             */
/*   Updated: 2017/03/31 15:08:31 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/vm.h"

void				exit_failure(char *format, char *arg, t_state *s)
{
	if (format && arg)
		ft_printf(format, arg);
	else if (format)
		ft_printf(format);
	clear_state(s);
	exit(EXIT_FAILURE);
}

unsigned char		*move_to(int bytes_num, unsigned char *pc,
						unsigned char *mem_start)
{
	unsigned char	*new_pos;

	bytes_num %= MEM_SIZE;
	new_pos = pc + bytes_num;
	if (new_pos > mem_start + MEM_SIZE - 1)
		new_pos -= MEM_SIZE;
	else if (new_pos < mem_start)
		new_pos += MEM_SIZE;
	return (new_pos);
}

int					read_mem(unsigned char size, unsigned char *ptr,
						unsigned char *arena)
{
	unsigned char	*str;
	int				num;
	int				i;

	i = size;
	str = (unsigned char*)ft_strnew(size);
	while (--i >= 0)
	{
		str[i] = *ptr;
		ptr = move_to(1, ptr, arena);
	}
	if (size == 1)
		num = *((char *)str);
	else if (size == 2)
		num = *((short*)str);
	else if (size == 4)
		num = *((int*)str);
	else
		num = 0;
	free(str);
	return (num);
}

void				write_mem(int val, unsigned char *ptr,
						unsigned char *arena)
{
	unsigned char	*cptr;
	int				i;

	cptr = ((unsigned char *)(&val)) + 3;
	i = 0;
	while (i < 4)
	{
		*ptr = *cptr;
		ptr = move_to(1, ptr, arena);
		cptr--;
		i++;
	}
}

int					get_arg_val(t_arg arg, t_process *p, unsigned char *arena,
							char bytes)
{
	int				val;
	unsigned char	*pos;

	if (arg.type == T_DIR)
		val = arg.val;
	else if (arg.type == T_IND)
	{
		pos = move_to(arg.val, p->pc, arena);
		val = read_mem(bytes, pos, arena);
	}
	else if (arg.type == T_REG && arg.val > 0 && arg.val <= REG_NUMBER)
		val = p->regs[arg.val - 1];
	else
		val = 0;
	return (val);
}
