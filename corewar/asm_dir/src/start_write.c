/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:48:23 by omartyno          #+#    #+#             */
/*   Updated: 2017/04/02 12:55:15 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asmblr.h"

void		input_magic(int fd)
{
	write_int_in(fd, COREWAR_EXEC_MAGIC, FALSE);
}

void		input_head(int fd, t_header head)
{
	input_magic(fd);
	write(fd, head.prog_name, PROG_NAME_LENGTH);
	write(fd, "\0\0\0", 4);
	write_int_in(fd, 0, FALSE);
	write(fd, head.comment, COMMENT_LENGTH);
	write(fd, "\0\0\0", 4);
}

void		input_commands(int fd_init, int fd, t_prpts *prop)
{
	size_t			line_now;
	t_arg_str		*ret;
	unsigned int	*val;
	t_label			*now;

	line_now = 0;
	while ((ret = get_cmd_start(fd_init, prop)))
	{
		prop->bc += ret->size;
		write(fd, ret->str, ret->size);
		free(ret->str);
		free(ret);
	}
	if (!prop->bc)
		go_error("Source file is empty (no commands readed)\n", prop);
	now = prop->head;
	while (now)
	{
		val = get_value(now->key, prop->table, prop->size);
		if (!val)
			label_err(now);
		lseek(fd, PROG_START + now->place, SEEK_SET);
		write_int_in(fd, *val - now->null_place, now->small);
		now = now->next;
	}
}

void		start_write(t_header head, int fd_init, char *name, t_prpts *prop)
{
	char	*hidden_name;
	char	*ok_name;
	int		fd;

	hidden_name = new_name(name, TRUE);
	change_unlink_name(hidden_name);
	fd = open(hidden_name, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	input_head(fd, head);
	input_commands(fd_init, fd, prop);
	lseek(fd, PROG_NAME_LENGTH + sizeof(int) * 2, SEEK_SET);
	write_int_in(fd, prop->bc, FALSE);
	ok_name = new_name(name, FALSE);
	link(hidden_name, ok_name);
	unlink(hidden_name);
	ft_putstr("Writing output program to ");
	ft_putstr(ok_name);
	ft_putstr("\n");
	free(hidden_name);
	free(ok_name);
}
