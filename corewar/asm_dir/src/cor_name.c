/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 12:09:58 by omartyno          #+#    #+#             */
/*   Updated: 2017/04/02 12:54:58 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asmblr.h"

size_t	find_hidden_place(char *name)
{
	size_t	i;
	size_t	hidden_place;

	hidden_place = 0;
	i = -1;
	while (name[++i])
		if (name[i] == '/')
			hidden_place = i + 1;
	return (hidden_place);
}

size_t	show_or_hide(char *init_name, t_bool hidden, size_t dot, char *new)
{
	size_t	i;
	size_t	hidden_place;

	hidden_place = find_hidden_place(init_name);
	i = -1;
	while (++i != dot + ((hidden) ? 1 : 0))
	{
		if (hidden && i == hidden_place)
			new[i] = '.';
		else
			new[i] = (hidden && i > hidden_place) ?
				init_name[i - 1] : init_name[i];
	}
	return (i);
}

char	*new_name(char *init_name, t_bool hidden)
{
	size_t	i;
	size_t	dot_place;
	char	*new;

	i = -1;
	dot_place = -1;
	while (init_name[++i])
	{
		if (init_name[i] == '.')
			dot_place = i;
		if (init_name[i] == '/')
			dot_place = (size_t)-1;
	}
	if (dot_place == (size_t)(-1))
		dot_place = i;
	new = (char *)malloc(sizeof(char) * (dot_place + 5 + ((hidden) ? 1 : 0)));
	i = show_or_hide(init_name, hidden, dot_place, new);
	new[i++] = '.';
	new[i++] = 'c';
	new[i++] = 'o';
	new[i++] = 'r';
	new[i] = '\0';
	return (new);
}
