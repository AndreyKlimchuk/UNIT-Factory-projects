/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 01:19:32 by omartyno          #+#    #+#             */
/*   Updated: 2017/04/02 09:47:29 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asmblr.h"
#define NO_ARGS "Not enough arguments for command\n"
#define FRMT_ERR "Arguments isn't well formatted\n"

void		code_type(char *ret, int *ret_now, t_arg one, t_bool small)
{
	char	*now;
	int		to;
	int		i;

	i = -1;
	if (one.type == REG_CODE)
		to = 0;
	if (one.type == IND_CODE)
		to = 1;
	if (one.type == DIR_CODE)
		to = (small) ? 1 : 3;
	now = (char *)(&one.value);
	now += to;
	while (++i < (to + 1))
		ret[(*ret_now)++] = *now--;
}

void		to_the_next(char *line, t_prpts *prop, t_bool last)
{
	if (last)
		return ;
	if (!line[prop->i])
		go_error(NO_ARGS, prop);
	if (line[prop->i] != SEPARATOR_CHAR)
		go_error(FRMT_ERR"Perhaps you forgot the separator\n", prop);
	(prop->i)++;
	skip_white_forw(line, &(prop->i));
	if (!line[prop->i])
		go_error(NO_ARGS, prop);
}

t_arg_str	*get_args(char *line, t_prpts *prop)
{
	t_arg_str		*ret;
	int				j;
	unsigned char	octal;
	t_arg			one;

	ret = (t_arg_str *)malloc(sizeof(t_arg_str));
	ret->str = ft_strnew(prop->now->arg_num * sizeof(int) +
								((prop->now->coding_byte) ? 2 : 1));
	j = -1;
	octal = 0;
	ret->size = ((prop->now->coding_byte) ? 2 : 1);
	while (++j < prop->now->arg_num)
	{
		skip_white_forw(line, &(prop->i));
		one = get_one(line, prop->now->arg_types[j], prop, ret->size);
		octal |= one.type << (3 - j) * 2;
		code_type(ret->str, &(ret->size), one, (prop->now->small_label));
		to_the_next(line, prop, (j == prop->now->arg_num - 1));
	}
	skip_white_forw(line, &(prop->i));
	if (line[prop->i])
		go_error("Too much arguments for command\n", prop);
	if (prop->now->coding_byte)
		ret->str[1] = octal;
	return (ret);
}

t_op		*recognize_cmd(char *line, t_prpts *prop)
{
	t_op	*ret;

	(prop->i) = 0;
	while (!(ft_iswhitespace(line[(prop->i)])) && line[(prop->i)])
		(prop->i)++;
	line[(prop->i)] = '\0';
	ret = get_ophsh(line);
	if (!ret)
		go_error("Wrong command\n", prop);
	line[(prop->i)] = ' ';
	return (ret);
}

t_arg_str	*make_cmd(char *line, t_prpts *prop)
{
	t_arg_str		*args;
	unsigned char	octal;

	prop->now = recognize_cmd(line, prop);
	octal = 0;
	args = get_args(line, prop);
	args->str[0] = (char)prop->now->opcode;
	prop->i = 0;
	return (args);
}
