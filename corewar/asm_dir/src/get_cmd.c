/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:46:42 by omartyno          #+#    #+#             */
/*   Updated: 2017/03/24 17:19:29 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asmblr.h"

size_t		check_label(char *line, t_prpts *prop)
{
	size_t	j;
	char	*label;

	j = 0;
	while (is_lblchar(line[j]))
		j++;
	if (line[j] != LABEL_CHAR && !(ft_iswhitespace(line[j])))
		go_error("Wrong character in string\n", prop);
	if (line[j] != LABEL_CHAR)
		return (0);
	label = (char *)malloc(sizeof(char) * (j + 1));
	j = -1;
	while (line[++j] != LABEL_CHAR)
		label[j] = line[j];
	label[j++] = '\0';
	add_value(prop->table, prop->size, label, prop->bc);
	skip_white_forw(line, &j);
	return (j);
}

t_arg_str	*parse_cmd_line(char *cmd_line, t_prpts *prop)
{
	t_arg_str	*ret;

	(prop->str_byte) = 0;
	skip_white_forw(cmd_line, &(prop->str_byte));
	(prop->str_byte) += check_label(cmd_line + (prop->str_byte), prop);
	if (cmd_line[(prop->str_byte)] != '\0')
		ret = make_cmd(cmd_line + (prop->str_byte), prop);
	else
	{
		ret = (t_arg_str *)malloc(sizeof(t_arg_str));
		ret->size = 0;
		ret->str = ft_strdup("");
	}
	return (ret);
}

t_arg_str	*get_cmd_start(int fd_in, t_prpts *prop)
{
	char		*cmd_line;
	t_arg_str	*ret;

	cmd_line = NULL;
	ret = NULL;
	while (get_next_line(fd_in, &cmd_line, prop))
		if (skip_comment(&cmd_line))
			continue ;
		else
			break ;
	if (cmd_line[0])
		ret = parse_cmd_line(cmd_line, prop);
	free(cmd_line);
	return (ret);
}
