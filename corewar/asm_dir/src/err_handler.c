/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:08:04 by omartyno          #+#    #+#             */
/*   Updated: 2017/04/02 09:59:16 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asmblr.h"

void	try_unlink(char *name, t_bool try)
{
	static char		*save = NULL;

	if (!try)
		save = name;
	else if (save)
		unlink(save);
}

void	line_number(size_t line_number)
{
	char	*num;
	char	*all;

	num = ft_itoa((int)line_number);
	all = (char *)malloc(sizeof(char) * (ft_strlen(num) + 9));
	ft_memmove(all, "[LINE: ", 7);
	ft_memmove(all + 7, num, ft_strlen(num));
	ft_memmove(all + 7 + ft_strlen(num), "]\n", 3);
	ft_putstr_fd(all, 2);
	free(all);
	free(num);
}

void	go_error(const char *err_message, t_prpts *prop)
{
	ft_putstr_fd(err_message, 2);
	if (prop)
		line_number(prop->str_now);
	try_unlink("", TRUE);
	exit(2);
}

void	label_err(t_label *lbl)
{
	if (lbl && lbl->key)
	{
		ft_putstr_fd("Nonexistent label name: \"", 2);
		ft_putstr_fd(lbl->key, 2);
		write(2, "\"\n", 2);
	}
	else
		ft_putstr_fd("Nonexistent label name\n", 2);
	line_number(lbl->line);
	try_unlink("", TRUE);
	exit(2);
}

void	change_unlink_name(char *name)
{
	try_unlink(name, FALSE);
}
