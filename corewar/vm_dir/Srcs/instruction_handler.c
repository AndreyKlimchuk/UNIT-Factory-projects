/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:08:54 by aklimchu          #+#    #+#             */
/*   Updated: 2017/03/31 14:43:37 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/vm.h"

unsigned char			get_type_size(unsigned char type, int opcode)
{
	if ((type == T_DIR && g_op_tab[opcode - 1].small_direct) || type == T_IND)
		return (2);
	else if (type == T_DIR)
		return (4);
	else if (type == T_REG)
		return (1);
	else
		return (0);
}

static unsigned char	interpret_type(unsigned char arg_code)
{
	if (arg_code == REG_CODE)
		return (T_REG);
	else if (arg_code == DIR_CODE)
		return (T_DIR);
	else if (arg_code == IND_CODE)
		return (T_IND);
	else
		return (0);
}

static void				read_args(t_arg *args, t_process *p,
							unsigned char *arena)
{
	unsigned char		*arg_ptr;
	unsigned char		i;

	i = 0;
	arg_ptr = move_to(g_op_tab[p->curr_opcode - 1].coding_byte + 1,
				p->pc, arena);
	while (i < g_op_tab[p->curr_opcode - 1].arg_num)
	{
		args[i].val = read_mem(get_type_size(args[i].type, p->curr_opcode),
						arg_ptr, arena);
		arg_ptr = move_to(get_type_size(args[i].type, p->curr_opcode),
					arg_ptr, arena);
		i++;
	}
}

static unsigned char	get_types(t_arg *args, t_process *p,
							unsigned char *arena)
{
	unsigned char		coding_byte;
	unsigned char		curr_type;
	unsigned char		arg_code;
	unsigned char		size;
	unsigned char		i;

	i = 0;
	size = 0;
	coding_byte = *(move_to(1, p->pc, arena));
	while (i < g_op_tab[p->curr_opcode - 1].arg_num)
	{
		arg_code = (coding_byte & (0xff >> (i * 2))) >> (6 - i * 2);
		curr_type = interpret_type(arg_code);
		if (g_op_tab[p->curr_opcode - 1].args_types[i] & curr_type)
			args[i].type = curr_type;
		else
			args[0].type = 0;
		size += get_type_size(curr_type, p->curr_opcode);
		i++;
	}
	return (size + 1);
}

unsigned char			eval_instruction(t_state *s, t_process *p)
{
	t_arg				*args;
	unsigned char		bytes_to_skip;

	args = (t_arg*)malloc(sizeof(t_arg) * g_op_tab[p->curr_opcode - 1].arg_num);
	if (g_op_tab[p->curr_opcode - 1].coding_byte)
	{
		bytes_to_skip = get_types(args, p, s->arena);
		if (!args[0].type)
		{
			free(args);
			return (bytes_to_skip);
		}
	}
	else
	{
		args[0].type = T_DIR;
		bytes_to_skip = (p->curr_opcode == 1) ? 4 : 2;
	}
	read_args(args, p, s->arena);
	g_instr_tab[p->curr_opcode - 1](args, p, s);
	free(args);
	return (bytes_to_skip);
}
